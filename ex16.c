#include <stdio.h>
#include <assert.h> // verifies assumption and prints diagnostic message if assumption is false
#include <stdlib.h> // defines several general purpose functions
#include <string.h> // defines several functions dealing with string and arrays

struct Person { // compound type that allows you to reference all 4 elements as one, or each piece by name
    char *name; // similar to a class
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person)); // allocate memory that is the size of the struct
    assert(who != NULL); // ensuring piece of memory is valid - checking pointer is not null (unset or invalid)

    // initialising variables - think of it like who.name in an OO language
    who->name = strdup(name); // duplicate string for the name
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who) // if you create, you always need to destroy, otherwise you get a memory leak
{
    assert(who != NULL);

    free(who->name); //frees the memory
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name); // like who.name, who,age in OO
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
        "Joe Alex", 32, 64, 140
    );

    struct Person *frank = Person_create(
        "Frank Blank", 20, 72, 180
    );

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight +=20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
