#include "entero.h"

Integer *new_integer(char **number_string) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Read number_string, put into Integer object
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

Integer *gcd(Integer *a, Integer *b) {
  Integer *zero = new_integer(0);
  if (a == 0 && b == 0) {
    return 0;
  } else if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  } else if (a >= b) {
    return gcd(b, module(a, b));
  } else {
    return gcd(a, module(b, a));
  }
}
