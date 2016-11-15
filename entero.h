#include <stdlib.h>

struct integer {
  /* Arreglo con los digitos del numero */
  char **digits;

  /* Cantidad de digitos del numero */
  size_t digits_count;
};

typedef struct integer Integer;

/* Crea un integer a partir de una cadena de string */
Integer *new_integer(char **number_string);

/* Entrega la suma de ambos enteros */
Integer *add(Integer *i1, Integer *i2);

/* Entrega la multiplicacion de ambos enteros */
Integer *mupltiply(Integer *i1, Integer *i2);

/* Entrega (numero modulo base) */
Integer *module(Integer *number, Integer *base);

/* Entrega la division entera entre numerador y divisor, y deja el resto en rest
 */
Integer *division_whole(Integer *numerator, Integer *divider, Integer **rest);
