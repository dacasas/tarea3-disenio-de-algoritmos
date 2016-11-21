from integer import Integer
import random


def test_primalidad(n, k):
    two = Integer("2")
    one = Integer("1")
    zero = Integer("0")
    if (n.equals(two)):
        return "PRIMO"
    elif (n.is_even() or n.is_power()):
        return "COMPUESTO"
    else:
        a = []
        for i in range(0, k):
            a.append(random.randint(1, n.to_int() - 1))
        b = []
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
            print("-------------break 4-------------------")
            return "COMPUESTO"
        else:
            return "PRIMO"
