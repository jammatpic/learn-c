#include <stdio.h>

int main(int argc, char *argv[])
{
  // go through each string in argv

  int i = argc;
  while (i > 0) {
    printf("arg %d: %s\n", argc-i, argv[argc-i]);
    i--;
  }

  // let's make our own array of strings
  /*
  char *states[] = {
    "California", "Oregon", "Washington", "Texas"
  };
  */

  char *states[4];
  i = 0;
  while (i < argc && i < 4) {
    states[i] = argv[i];
    i++;
  }

  int num_states = 4;
  i = 0; // watch for this
  while(i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return 0;
}
