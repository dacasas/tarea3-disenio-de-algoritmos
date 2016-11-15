#include "entero.h"
#include <stdio.h>

int main(int argc, char **argv) {
  if (argc == 2) {
    // It is a file
  } else {
    // There are two numbers as arguments
    if (argc > 3) {
      printf("%s\n", "You must give two numbers as arguments, or a file with "
                     "the expected format.");
      exit(0);
    }

    char *first_number = argv[1];
    char *second_number = argv[2];

    printf("%i\n", first_number[0]);
    printf("%i\n", first_number[1]);
    printf("%s\n", second_number);
  }

  /* code */
  return 0;
}
