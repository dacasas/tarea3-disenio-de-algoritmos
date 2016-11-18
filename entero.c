#include "entero.h"

Integer *new_integer(char *number_string, int8_t sign) {
  Integer *i = (Integer *)malloc(sizeof(Integer));

  const char *s;
  for (s = number_string; *s; ++s) {
  }
  i->digits_count = (s - number_string);

  i->digits = (int8_t *)malloc((i->digits_count) * sizeof(int8_t));

  for (size_t pos = 0; pos < i->digits_count; pos++) {
    i->digits[pos] = number_string[pos] - 48;
  }

  i->sign = sign;
  return i;
}

Integer *remove_first_pos(Integer *a) {
  Integer *n = (Integer *)malloc(sizeof(Integer));
  n->digits_count = a->digits_count - 1;
  n->digits = (int8_t *)malloc(sizeof(int8_t) * n->digits_count);
  for (size_t m = 1; m < a->digits_count; m++) {
    n->digits[m - 1] = a->digits[m];
  }
  free_integer(a);
  return n;
}

/* Transform "a" to Integer type */
Integer *get_integer(int8_t a) {
  char m = a;
  if (a < 0) {
    return new_integer(&m, -1);
  } else {
    return new_integer(&m, 1);
  }
}

Integer *add(Integer *a, Integer *b) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  if (a->digits_count > b->digits_count) {
    i->digits_count = a->digits_count + 1;
  } else {
    i->digits_count = b->digits_count + 1;
  }

  i->digits = (int8_t *)malloc(sizeof(int8_t) * i->digits_count);
  for (size_t index = 0; index < i->digits_count; index++) {
    i->digits[index] = 0;
  }

  int64_t count_a = a->digits_count - 1;
  int64_t count_b = b->digits_count - 1;
  int64_t count_result = i->digits_count - 1;
  int8_t charge = 0;
  while (count_a >= 0 && count_b >= 0) {
    int8_t result = a->digits[count_a] + b->digits[count_b] + charge;
    if (result < 10) {
      i->digits[count_result] = result;
      charge = 0;
    } else {
      i->digits[count_result] = result - 10;
      charge = 1;
    }

    count_a--;
    count_b--;
    count_result--;
  }

  while (count_a >= 0) {
    int8_t result = a->digits[count_a] + charge;
    if (result < 10) {
      i->digits[count_result] = result;
      charge = 0;
    } else {
      i->digits[count_result] = result - 10;
      charge = 1;
    }

    count_a--;
  }

  while (count_b >= 0) {
    int8_t result = b->digits[count_b] + charge;
    if (result < 10) {
      i->digits[count_result] = result;
      charge = 0;
    } else {
      i->digits[count_result] = result - 10;
      charge = 1;
    }

    count_b--;
  }

  if (charge == 1) {
    i->digits[0] = 1;
  } else {
    Integer *n = remove_first_pos(i);
    i = n;
  }

  printf("%s", "Adding ");
  print_integer(a);
  printf("%s", " + ");
  print_integer(b);
  printf("%s", " = ");
  print_integer(i);
  printf("%s\n", "");

  return i;
}

Integer *mupltiply(Integer *a, Integer *b) {
  Integer *i = (Integer *)malloc(sizeof(Integer));

  return i;
}

Integer *module(Integer *number, Integer *base) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements module operation for Integer struct
  return i;
}

Integer *division_whole(Integer *numerator, Integer *divider, Integer *rest) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  rest = (Integer *)malloc(sizeof(Integer));

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

char equalsToDigit(Integer *a, int8_t digit) {
  return (a->digits_count == 1 && a->digits[0] == digit);
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

char is_power(Integer *a) { return 1; }

char has_square_root(Integer *n, Integer *k, Integer *i, Integer *j) {
  return 1;
}

/* Returns the index of the greatest argument */
char greater(Integer *a, Integer *b) {
  if (a->digits_count > b->digits_count) {
    return 0;
  } else if (a->digits_count < b->digits_count) {
    return 1;
  } else {
    if (a->digits[0] > b->digits[0]) {
      return 0;
    } else {
      return 1;
    }
  }
}

Integer *exponential(Integer *base, Integer *exponent) {}

char is_even(Integer *a) { return 1; }

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
