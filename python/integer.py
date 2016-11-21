class Integer:
    def __init__(self, string_number):
        if (string_number[0] == "-"):
            self.sign = -1
            string_number = string_number[1:]
        else:
            self.sign = 1
        self.digits = list(reversed([int(s) for s in string_number]))

    @classmethod
    def get_integer(self, digits_list):
        a = Integer("12")
        a.digits = digits_list
        a.sign = 1
        return a

    def to_int(self):
        final = 0
        count = 1
        for digit in self.digits:
            final += digit * count
            count *= 10
        return final

    def get_string(self):
        a = ""
        if (self.sign == -1):
            a += "-"
        for digit in reversed(self.digits):
            a += str(digit)
        return a

    def equals(self, integer_b):
        return self.digits == integer_b.digits

    def greater_than(self, integer_b):
        if (len(self.digits) > len(integer_b.digits)):
            return (self.sign == 1)
        elif (len(self.digits) < len(integer_b.digits)):
            return not (integer_b.sign == 1)
        else:
            for i in range(len(self.digits) - 1, -1, -1):
                if self.digits[i] > integer_b.digits[i]:
                    return (self.sign == 1)
                elif self.digits[i] < integer_b.digits[i]:
                    return not (integer_b.sign == 1)
            return False

    def clean_zeroes(self):
        count = len(self.digits) - 1

        while (self.digits[count] == 0 and count > 0):
            count -= 1

        self.digits = self.digits[0:count + 1]

    def add(self, b):
        result = []
        charge = 0
        for i in range(0, min(len(self.digits), len(b.digits))):
            tmp_result = self.digits[i] + b.digits[i] + charge
            if (tmp_result < 10):
                result.append(tmp_result)
                charge = 0
            else:
                result.append(tmp_result - 10)
                charge = 1

        for i in range(len(result), len(self.digits)):
            tmp_result = self.digits[i] + charge
            if (tmp_result < 10):
                result.append(tmp_result)
                charge = 0
            else:
                result.append(tmp_result - 10)
                charge = 1

        for i in range(len(result), len(b.digits)):
            tmp_result = b.digits[i] + charge
            if (tmp_result < 10):
                result.append(tmp_result)
                charge = 0
            else:
                result.append(tmp_result - 10)
                charge = 1

        if (charge == 1):
            result.append(1)

        integer_result = Integer("123")
        integer_result.digits = result
        integer_result.sign = 1

        return integer_result

    def plus_one(self):
        charge = 1
        for i in range(0, len(self.digits)):
            k = self.digits[i] + 1
            if (k < 10):
                self.digits[i] = k
                charge = 0
                break
            else:
                self.digits[i] = k - 10
                charge = 1

        if (charge == 1):
            self.digits.append(1)

    def substract(self, b):
        if (b.greater_than(self)):
            m = b.substract(self)
            m.sign = -1
            return m

        result = []
        charge = 0
        for i in range(0, len(b.digits)):
            tmp_result = self.digits[i] - b.digits[i] - charge
            if (tmp_result >= 0):
                result.append(tmp_result)
                charge = 0
            else:
                result.append(tmp_result + 10)
                charge = 1

        for i in range(len(result), len(self.digits)):
            tmp_result = self.digits[i] - charge
            if (tmp_result >= 0):
                result.append(tmp_result)
                charge = 0
            else:
                result.append(tmp_result + 10)
                charge = 1

        m = Integer("123")
        m.digits = result
        m.sign = 1
        m.clean_zeroes()

        return m

    def divide_super_naive(self, b):
        if (b.greater_than(self)):
            return Integer("0"), Integer(self.get_string())

        result = Integer("0")
        if (self.equals(result)):
            return (result, result)
        rest = self

        while (rest.greater_than(b) or rest.equals(b)):
            rest = rest.substract(b)
            result.plus_one()
        rest.clean_zeroes()
        return (result, rest)

    def divide(self, b):
        if (b.greater_than(self)):
            return Integer("0"), Integer(self.get_string())

        super_result = Integer("123")
        super_result.digits = []
        actual_index = len(self.digits) - 1
        rest = Integer("123")
        rest.digits = []

        while (actual_index >= 0):
            rest.digits = [self.digits[actual_index]] + rest.digits
            rest.clean_zeroes()

            while (b.greater_than(rest) and
                    not rest.equals(Integer("0")) and actual_index > 0):
                actual_index -= 1
                rest.digits = [self.digits[actual_index]] + rest.digits

            result, rest = rest.divide_super_naive(b)
            super_result.digits = result.digits + super_result.digits

            if (actual_index == 0 and b.greater_than(rest)):
                break

            actual_index -= 1

        return (super_result, rest)

    def module(self, b):
        integer = self.divide(b)
        return integer[1]

    def multiply(self, b):
        if (len(self.digits) > len(b.digits)):
            dif = len(self.digits) - len(b.digits)
            b.digits = b.digits + [0]*dif

        else:
            dif = len(b.digits) - len(self.digits)
            self.digits = self.digits + [0]*dif

        return self.multiply_karatsuba(b)

    def multiply_karatsuba(self, b):
        zero = Integer("0")
        if (self.equals(zero) or b.equals(zero)):
            return zero

        if (len(self.digits) == len(b.digits) == 1):
            result = self.digits[0] * b.digits[0]
            digits = [int(x) for x in str(result)]
            integer = Integer.get_integer(list(reversed(digits)))
            integer.clean_zeroes()
            return integer

        n = len(self.digits)

        split_position = int(n / 2)
        a1 = Integer.get_integer(self.digits[split_position:])
        a2 = Integer.get_integer(self.digits[:split_position])
        b1 = Integer.get_integer(b.digits[split_position:])
        b2 = Integer.get_integer(b.digits[:split_position])

        a1.clean_zeroes()
        a2.clean_zeroes()
        b1.clean_zeroes()
        b2.clean_zeroes()

        c1 = a1.multiply(b1)
        c2 = a2.multiply(b2)
        c3 = (a1.add(a2)).multiply(b1.add(b2))

        m = (c3.substract(c1.add(c2)))
        m.clean_zeroes()

        c1.digits = [0]*(split_position * 2) + c1.digits
        m.digits = [0]*(split_position) + m.digits

        result = (c1.add(m)).add(c2)
        result.clean_zeroes()

        return result

    def gcd(self, b):
        zero = Integer("0")
        if (self.equals(zero) and b.equals(zero)):
            return exit(0)
        elif (self.equals(zero)):
            return b
        elif (b.equals(zero)):
            return self
        elif (b.greater_than(self)):
            return self.gcd(b.module(self))
        else:
            return b.gcd(self.module(b))

    def is_power(self):
        three = Integer("3")
        if (three.greater_than(self) or three.equals(self)):
            return False
        else:
            one = Integer("1")
            two = Integer("2")
            k = Integer("2")

            # m = 2^k
            m = two.multiply(two)

            # while (2^k <= n) <=> k <= log_2(n)
            while (self.greater_than(m) or self.equals(m)):
                if (self.has_square_root(k, one, self)):
                    return True
                k.plus_one()
                m = m.multiply(two)

            return False

    def has_square_root(self, k, i, j):
        two = Integer("2")
        one = Integer("1")
        if (i.equals(j)):
            tmp = i.exp(k)
            return tmp.equals(self)
        elif (j.greater_than(i)):
            p = (i.add(j)).divide(two)[0]
            val = p.exp(k)
            if (self.equals(val)):
                return True
            elif (self.greater_than(val)):
                p.plus_one()
                return self.has_square_root(k, p, j)
            else:
                p1 = p.substract(one)
                return self.has_square_root(k, i, p1)
        else:
            return False

    def exp(self, exponent):
        one = Integer("1")
        two = Integer("2")
        if (exponent.equals(one)):
            return Integer(self.get_string())
        elif (exponent.is_even()):
            result = self.exp(exponent.divide(two)[0])
            return result.multiply(result)
        else:
            expo = exponent.substract(one)
            result = self.exp(expo.divide(two)[0])
            mid = result.multiply(result)
            return mid.multiply(self)

    def exp_mod(self, exponent, n):
        one = Integer("1")
        two = Integer("2")
        if (exponent.equals(one)):
            return Integer(self.get_string())
        elif (exponent.is_even()):
            tmp = self.exp_mod(exponent.divide(two)[0], n)
            result = tmp.multiply(tmp)
            asd = result.module(n)
            return asd
        else:
            expo = exponent.substract(one)
            tmp = self.exp_mod(expo.divide(two)[0], n)
            mid = tmp.multiply(tmp)
            mid2 = mid.multiply(self)
            asd = mid2.module(n)
            return asd

    def is_even(self):
        last = self.digits[0]
        return (last == 0 or last == 2 or last == 4 or last == 6 or last == 8)
