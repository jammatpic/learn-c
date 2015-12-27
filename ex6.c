#include <stdio.h>

int main(int argc, char *argv[])
{
  int distance = 100;  //integers: declare with 'int', print with %d (16 bits)
  float power = 2.345f;  //floats: declare with 'float', print with %f
  double super_power = 56789.4532;  //double precision float: declare with 'double', print with %f
  char initial = 'A';  //char: declare with 'char', print with %c, written with single quote around the character
  char first_name[] = "Zed";  //string: declare with 'char name[]', print with %s, written with double quotes
  char last_name[] = "Shaw";  //remember, strings are arrays of chars in C.

  printf("You are %d miles away.\n", distance);
  printf("You have %f levels of power.\n", power);
  printf("You have %f awesome superpowers.\n", super_power);
  printf("I have an initial %c.\n", initial);
  printf("I have a first name %s.\n", first_name);
  printf("I have a last name %s.\n", last_name);
  printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);

  return 0;
}
