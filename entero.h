#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct integer {
  /* Arreglo con los digitos del numero */
  int8_t *digits;

  /* Cantidad de digitos del numero */
  size_t digits_count;
};

typedef struct integer Integer;

/* Crea un integer a partir de una cadena de string */
Integer *new_integer(char *number_string);

/* Entrega la suma de ambos enteros */
Integer *add(Integer *a, Integer *b);

/* Entrega la multiplicacion de ambos enteros */
Integer *mupltiply(Integer *a, Integer *b);

/* Entrega (numero modulo base) */
Integer *module(Integer *number, Integer *base);

/* Entrega la division entera entre numerador y divisor, y deja el resto en rest
 */
Integer *division_whole(Integer *numerator, Integer *divider, Integer **rest);

/* Entrega el resultado de base^exponent */
Integer *exp(Integer *base, Integer *exponent);

/* Entrega el resultado de base^exponent mod n */
Integer *exp(Integer *base, Integer *exponent, Integer *n);

/* Entrega 1 si son iguales, 0 en el caso contrario */
char equals(Integer *a, Integer *b);

/* Entrega 1 si es igual a 0, 0 en otro caso*/
char equalsToZero(Integer *a);

/* Entrega el maximo comun divisor (MCD) entre a y b */
Integer *gcd(Integer *a, Integer *b);

/* Imprime el arreglo de digitos */
void print_integer(Integer *a);

/* Libera la memoria usada por el entero a */
void free_integer(Integer *a);

/* Entrega 1 si a es potencia de otro numero, 0 en caso contrario */
char is_power(Integer *a);

/* Entrega 1 si a tiene raiz entera, 0 en caso contrario */
char has_square_root(Integer *n, Integer *k, Integer *i, Integer *j);

/* Retorna un numero aleatorio en el intervalo [0, max] */
long random_at_most(long max);
