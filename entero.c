#include "entero.h"

Integer *new_integer(char *number_string) {
  Integer *i = (Integer *)malloc(sizeof(Integer));

  const char *s;
  for (s = number_string; *s; ++s) {
  }
  i->digits_count = (s - number_string);

  // If first character is "-" (45 ASCII) remove it
  if (number_string[0] == 45) {
    i->sign = -1;
    i->digits_count--;
  } else {
    i->sign = 1;
  }

  i->digits = (int8_t *)malloc((i->digits_count) * sizeof(int8_t));

  if (number_string[0] == 45) {
    for (size_t pos = 0; pos < i->digits_count; pos++) {
      i->digits[pos] = number_string[pos + 1] - 48;
    }
  } else {
    for (size_t pos = 0; pos < i->digits_count; pos++) {
      i->digits[pos] = number_string[pos] - 48;
    }
  }

  return i;
}

void print_integer(Integer *a) {
  if (a->sign == -1) {
    printf("%s", "-");
  }
  for (size_t i = 0; i < a->digits_count; i++) {
    printf("%i", a->digits[i]);
  }
}

void free_integer(Integer *a) {
  if (a) {
    if (a->digits) {
      free(a->digits);
    }
    free(a);
  }
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

char equalsToDigit(Integer *a, int8_t digit) {
  return (a->digits_count == 1 && a->digits[0] == digit);
}

Integer *remove_pos(Integer *a, size_t k) {
  if (k == 0) {
    return a;
  }

  Integer *n = (Integer *)malloc(sizeof(Integer));
  if (a->digits_count > k) {
    n->digits_count = a->digits_count - k;
    n->digits = (int8_t *)malloc(sizeof(int8_t) * n->digits_count);

    for (size_t m = k; m < a->digits_count; m++) {
      n->digits[m - k] = a->digits[m];
    }
  } else {
    n->digits_count = 1;
    n->digits = (int8_t *)malloc(sizeof(int8_t));
    n->digits[0] = 0;
  }
  n->sign = a->sign;

  free_integer(a);

  return n;
}

Integer *clean_zeroes(Integer *a) {
  if (a->digits[0] != 0 || equalsToDigit(a, 0)) {
    return a;

  } else {
    size_t count = 0;
    int8_t zero = a->digits[count];

    while (zero == 0 && count < a->digits_count - 1) {
      count++;
      zero = a->digits[count];
    }

    return remove_pos(a, count);
  }
}

char is_greater(Integer *a, Integer *b) {
  if (a->digits_count > b->digits_count) {

    if (a->sign == 1) {
      return 1;
    } else {
      return 0;
    }

  } else if (a->digits_count < b->digits_count) {

    if (b->sign == 1) {
      return 0;
    } else {
      return 1;
    }

  } else {

    size_t count = 0;

    while (count < a->digits_count) {
      if (a->digits[count] > b->digits[count]) {

        if (a->sign == 1) {
          return 1;
        } else {
          return 0;
        }

      } else if (a->digits[count] < b->digits[count]) {

        if (b->sign == 1) {
          return 0;
        } else {
          return 1;
        }
      }

      count++;
    }
    return 0;
  }
}

Integer *get_digit(int8_t d) {
  Integer *digit = (Integer *)malloc(sizeof(Integer));
  digit->digits_count = 1;
  digit->digits = (int8_t *)malloc(sizeof(int8_t));
  digit->digits[0] = d;

  return digit;
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
    count_result--;
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
    count_result--;
  }

  // Assume always we will add two possitive numbers
  i->sign = 1;

  if (charge == 1) {
    i->digits[0] = 1;
    return i;
  } else {
    Integer *ret = remove_pos(i, 1);
    return ret;
  }
}

Integer *plus_one(Integer *a) {
  Integer *b = get_digit(1);
  Integer *result = add(a, b);
  free_integer(b);
  free_integer(a);
  return result;
}

Integer *substract(Integer *a, Integer *b) {

  if (is_greater(b, a)) {
    Integer *result = substract(b, a);
    result->sign = -1;
    return result;
  }

  Integer *i = (Integer *)malloc(sizeof(Integer));
  if (a->digits_count > b->digits_count) {
    i->digits_count = a->digits_count;
  } else {
    i->digits_count = b->digits_count;
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
    if (a->digits[count_a] > b->digits[count_b]) {
      i->digits[count_result] =
          a->digits[count_a] - b->digits[count_b] - charge;
      charge = 0;

    } else if (a->digits[count_a] < b->digits[count_b]) {
      i->digits[count_result] =
          a->digits[count_a] + 10 - b->digits[count_b] - charge;
      charge = 1;

    } else {
      i->digits[count_result] = charge * 9;
    }

    count_a--;
    count_b--;
    count_result--;
  }

  while (count_a >= 0) {
    if (charge == 1) {
      i->digits[count_result] = a->digits[count_a] - 1;
      charge = 0;
    } else {
      i->digits[count_result] = a->digits[count_a];
    }

    count_a--;
    count_result--;
  }

  i->sign = 1;

  Integer *asd = clean_zeroes(i);

  return asd;
}

Integer *mupltiply(Integer *a, Integer *b) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  if (a->digits_count == 1 || b->digits_count == 1) {
    if (a->digits_count == 1) {
      // For each number in b, multiply by a
      return b;
    } else {
      // For each number in a multiply by b
      return a;
    }
  } else if (a->digits_count == 0 || b->digits_count == 0) {
    if (a->digits_count == 0) {
      // For each number in b, multiply by a
      return a;
    } else {
      // For each number in a multiply by b
      return b;
    }
  } else {
    // asdfasef
  }
  return i;
}

Integer *module(Integer *number, Integer *base) {
  Integer *i;
  divide(number, base, &i);
  return i;
}

Integer *copy_integer(Integer *a) {
  Integer *b = (Integer *)malloc(sizeof(Integer));
  b->digits_count = a->digits_count;
  b->digits = (int8_t *)malloc(sizeof(int8_t) * b->digits_count);
  for (size_t i = 0; i < b->digits_count; i++) {
    b->digits[i] = a->digits[i];
  }
  b->sign = a->sign;
  return b;
}

Integer *divide(Integer *numerator, Integer *divider, Integer **rest) {
  Integer *result = get_digit(0);
  Integer *quedando = copy_integer(numerator);
  Integer *tmp;
  Integer *tmp2;

  while (is_greater(quedando, divider) || equals(quedando, divider)) {
    tmp = substract(quedando, divider);
    free_integer(quedando);
    quedando = tmp;

    tmp2 = plus_one(result);
    result = tmp2;
  }

  *rest = quedando;

  return result;
}

Integer *gcd(Integer *a, Integer *b) {
  if (equalsToDigit(a, 0) && equalsToDigit(b, 0)) {
    return 0;
  } else if (equalsToDigit(a, 0)) {
    return b;
  } else if (equalsToDigit(b, 0)) {
    return a;
  } else if (a >= b) {
    return gcd(b, module(a, b));
  } else {
    return gcd(a, module(b, a));
  }
}

char is_power(Integer *a) { return 1; }

char has_square_root(Integer *n, Integer *k, Integer *i, Integer *j) {
  return 1;
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
