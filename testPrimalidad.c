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

    // Integer **a = (Integer **)malloc(sizeof(Integer) * (argc - 1));

    // for (int i = 1; i < argc; i++) {
    //  a[i - 1] = new_integer(argv[i]);
    //}

    // Integer *result = add(a[0], a[1]);

    // free_integer(a[0]);
    // free_integer(a[1]);

    // free_integer(result);

    // free(a);

    int8_t a = 23;
    Integer *i = get_integer(a);
    print_integer(i);
  }

  /* code */
  return 0;
}
