#include "entero.h"

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

    Integer **a = (Integer **)malloc(sizeof(Integer) * (argc - 1));

    for (int i = 1; i < argc; i++) {
      a[i - 1] = new_integer(argv[i]);
    }

    Integer *rest;
    Integer *result = divide(a[0], a[1], &rest);

    printf("%s", "Resultado: ");
    print_integer(result);
    printf("%s\n", "");
    printf("%s", "Resto: ");
    print_integer(rest);
    printf("%s\n", "");

    if (a[0]) {
      free_integer(a[0]);
    }

    if (a[1]) {
      free_integer(a[1]);
    }

    if (rest) {
      free_integer(rest);
    }

    if (result) {
      free_integer(result);
    }

    free(a);
  }

  /* code */
  return 0;
}
