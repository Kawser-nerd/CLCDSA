#!/usr/bin/env python3
import math
import random

class Prime:
    seed_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

    def is_prime(self, n):
        is_prime_common = self.is_prime_common(n)
        if is_prime_common is not None:
            return is_prime_common

        if n < 2000000:
            return self.is_prime_bf(n)
        else:
            return self.is_prime_mr(n)

    def is_prime_common(self, n):
        if n == 1: return False
        if n in Prime.seed_primes: return True
        if any(map(lambda x: n % x == 0, self.seed_primes)): return False

    def is_prime_bf(self, n):
        for k in range(2, int(math.sqrt(n)) + 1):
            if n % k == 0:
                return False
        return True

    def is_prime_mr(self, n):
        d = n - 1
        while d % 2 == 0:
            d //= 2

        witnesses = self.get_witnesses(n)
        #witnesses = [random.randint(1, n - 1) for _ in range(100)]

        for w in witnesses:
            t = d
            y = pow(w, t, n)

            while t != n - 1 and y != 1 and y != n - 1:
                y = (y ** 2) % n
                t *= 2

            if y != n - 1 and t % 2 == 0:
                return False

        return True

    def get_witnesses(self, num):
        def _get_range(num):
            if num < 2047:
                return 1
            if num < 1373653:
                return 2
            if num < 25326001:
                return 3
            if num < 3215031751:
                return 4
            if num < 2152302898747:
                return 5
            if num < 3474749660383:
                return 6
            if num < 341550071728321:
                return 7
            if num < 38255123056546413051:
                return 9
            return 12

        return self.seed_primes[:_get_range(num)]

    def gcd(self, a, b):
        if a < b:
            a, b = b, a
        while b:
            a, b = b, a % b
        return a

    @staticmethod
    def f(x, n, seed):
        p = Prime.seed_primes[seed % len(Prime.seed_primes)]
        return (p * x + seed) % n

    def find_factor(self, n, seed=1):
        if self.is_prime(n):
            return n

        x, y, d = 2, 2, 1
        count = 0
        while d == 1:
            count += 1
            x = self.f(x, n, seed)
            y = self.f(self.f(y, n, seed), n, seed)
            d = self.gcd(abs(x - y), n)

        if d == n:
            return self.find_factor(n, seed+1)
        return self.find_factor(d)

    def find_factors(self, n):
        primes = {}
        if self.is_prime(n):
            primes[n] = 1
            return primes

        while n > 1:
            factor = self.find_factor(n)

            primes.setdefault(factor, 0)
            primes[factor] += 1

            n //= factor

        return primes

prime = Prime()

M = 10 ** 9 + 7


def solve(a, b):

    factors = {}
    for x in range(a, b, -1):
        f = prime.find_factors(x)
        for k, v in f.items():
            if k in factors:
                factors[k] += v
            else:
                factors[k] = v

    ans = 1
    for v in factors.values():
        ans *= v + 1
        ans %= M

    return ans


def main():
    a, b = input().split()
    a = int(a)
    b = int(b)


    print(solve(a, b))


if __name__ == '__main__':
    main()