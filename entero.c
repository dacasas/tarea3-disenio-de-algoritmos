#include "entero.h"

Integer *new_integer(char *number_string) {
  Integer *i = (Integer *)malloc(sizeof(Integer));

  const char *s;
  for (s = number_string; *s; ++s) {
  }
  i->digits_count = (s - number_string);

  i->digits = (int8_t *)malloc((i->digits_count) * sizeof(int8_t));

  for (size_t pos = 0; pos < i->digits_count; pos++) {
    i->digits[pos] = number_string[pos] - 48;
  }
  return i;
}

Integer *add(Integer *a, Integer *b) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements addition methos for Integer struct
  return i;
}

Integer *mupltiply(Integer *a, Integer *b) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements multiplication for Integer struct
  return i;
}

Integer *module(Integer *number, Integer *base) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements module operation for Integer struct
  return i;
}

Integer *division_whole(Integer *numerator, Integer *divider, Integer **rest) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements division for Integer struct
  return i;
}

Integer *power(Integer *base, Integer *exponent) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements powers
  return i;
}

char equals(Integer *a, Integer *b) {
  if (a->digits_count != b->digits_count) {
    return 0;
  } else {
    for (size_t i = 0; i < a->digits_count; i++) {
      if (a->digits[i] != b->digits[i]) {
        return 0;
      }
    }
    return 1;
  }
}

char equalsToZero(Integer *a) {
  return (a->digits_count == 1 && a->digits[0] == 0);
}

Integer *gcd(Integer *a, Integer *b) {
  if (equalsToZero(a) && equalsToZero(b)) {
    return 0;
  } else if (equalsToZero(a)) {
    return b;
  } else if (equalsToZero(b)) {
    return a;
  } else if (a >= b) {
    return gcd(b, module(a, b));
  } else {
    return gcd(a, module(b, a));
  }
}

void print_integer(Integer *a) {
  for (size_t i = 0; i < a->digits_count; i++) {
    printf("%i", a->digits[i]);
  }
}

void free_integer(Integer *a) {
  if (a->digits) {
    free(a->digits);
  }
  free(a);
}

char is_power(Integer *a) {}

char has_square_root(Integer *n, Integer *k, Integer *i, Integer *j) {}

Integer *exp(Integer *n, Integer *k) {}

long random_at_most(long max) {
  unsigned long
      // max <= RAND_MAX < ULONG_MAX, so this is okay.
      num_bins = (unsigned long)max + 1,
      num_rand = (unsigned long)RAND_MAX + 1, bin_size = num_rand / num_bins,
      defect = num_rand % num_bins;

  long x;
  do {
    x = random();
  } while (num_rand - defect <= (unsigned long)x);

  // Truncated division is intentional
  return x / bin_size;
}
