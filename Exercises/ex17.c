#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// THIS CODE DOESN'T WORK FOR SOME REASON

#define MAX_DATA 512 // uses C pre-processor to create constants that work reliably
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA]; // usage of constants results in fixed-size structs - less efficient, but easier to store/read
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message) // kills program with an error if anything is wrong
{
    if (errno) { // if a function returns an error, print it
        perror(message);
    } else { // else, print the specified error
        printf("ERROR: %s\n", message);
    }
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file); // fread(pointer, size, num_of_elements, stream)
    if (rc != 1) die("Failed to load database."); // fread() returns the total amount of elements successfully read
}

struct Connection *Database_open(const char *filename, char mode)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error"); // checking memory is valid, i.e. if conn is null, then there is an error

    if (mode == 'c') { // if creating, then open file to write
        conn->file = fopen(filename, "w");
    } else { // otherwise, open file for reading and writing
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) die("Failed to open the file"); // if conn->file is null, the target file has not been opened

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file) fclose(conn->file); // if conn->file is not null, flushes any data in the buffer to the file, closes the file, and releases any memory it used
        if (conn->db) free(conn->db); // free() frees memory previously allocated
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file); //goes to start of file

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file); // writes data from array poitned to to a given stream
    if (rc != 1) die("Failed to write database.");                     // fwrite(pointer, size, num_of_elements, file)

    rc = fflush(conn->file);
    if (rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialise it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) die("Already set, delete it first.");

    addr->set = 1;
    // WARNING: bug, read the "How To Break It" and fix this
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate the strncpy bug
    if (!res) die("Name copy failed");

    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) die("Email copy failed");
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur-> set) {
            Address_print(cur);
        }
    }
}

int main(int argc, char *argv[])
{
    printf("derp!");
    if (argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");
    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;
    if (argc > 3) id = atoi(argv[3]);
    if (id >= MAX_ROWS) die("There's not that many records.");

    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;

        case 'g':
            if (argc != 4) die("Need an ID to get");

            Database_get(conn, id);
            break;

        case 's':
            if (argc != 6) die("Need id, name, email to set");

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if (argc != 4) die("Need id to delete");

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
        default:
            die("Invalid action, only: c = create, g = get, s = set, d = del, l = list");
    }

    Database_close(conn);

    return 0;
}
