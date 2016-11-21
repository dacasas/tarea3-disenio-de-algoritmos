from integer import Integer
from random import sample
import sys


def test_primalidad(n, k):
    two = Integer("2")
    one = Integer("1")
    zero = Integer("0")
    if (n.equals(two)):
        return "PRIMO"
    elif (n.is_even() or n.is_power()):
        return "COMPUESTO"
    else:
        a = sample(range(1, n.to_int()), k)
        b = []
        print(a)
        for a_i in a:
            integer_ai = Integer(str(a_i))
            gcd_i = integer_ai.gcd(n)
            if (gcd_i.greater_than(one)):
                return "COMPUESTO"
            else:
                exponent = n.substract(one).divide(two)[0]
                b_i = integer_ai.exp_mod(exponent, n)
                b.append(b_i)
        neg = 0
        for b_i in b:
            if (b_i.add(one).module(n).equals(zero)):
                neg += 1
            elif (not b_i.substract(one).module(n).equals(zero)):
                return "COMPUESTO"
        if (neg == 0):
            return "COMPUESTO"
        else:
            return "PRIMO"


arguments = sys.argv
if (len(arguments) == 2):
    # It's a file
    dir = arguments[1]

elif (len(arguments) == 3):
    n = Integer(arguments[1])
    k = int(arguments[2])
    print(test_primalidad(n, k))

else:
    print("You must write a file dir to get an output file with the results, or two numbers to get the result directly")
    exit(0)
