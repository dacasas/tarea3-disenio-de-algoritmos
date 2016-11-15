#include "entero.h"

Integer *new_integer(char **number_string) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Read number_string, put into Integer object
  return i;
}

Integer *add(Integer *i1, Integer *i2) {
  Integer *i = (Integer *)malloc(sizeof(Integer));
  // TODO Implements addition methos for Integer struct
  return i;
}

Integer *mupltiply(Integer *i1, Integer *i2) {
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
