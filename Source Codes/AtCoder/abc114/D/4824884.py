#!/usr/bin/env python3
import sys


def solve(N: int):
    def is_prime(n):
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            i += 1
        return True
    def comb(n, k):
        if n < k:
            return 0
        ret = 1
        for i in range(k):
            ret *= n - i
            ret //= (i + 1)
        return ret
    primes = []
    for i in range(2, N + 1):
        if is_prime(i):
            primes.append(i)

    count = [0] * (N + 1)
    def count_up(n):
        for p in primes:
            while n >= p and n % p == 0:
                count[p] += 1
                n //= p
        return
    for i in range(2, N + 1):
        count_up(i)
    count.sort(reverse=True)
    over_75 = 0
    over_25 = 0
    over_15 = 0
    over_5 = 0
    over_3 = 0
    for c in count:
        if c >= 2:
            over_3 += 1
        if c >= 4:
            over_5 += 1
        if c >= 14:
            over_15 += 1
        if c >= 24:
            over_25 += 1
        if c >= 74:
            over_75 += 1
    ret = (over_75 + over_25 * (over_3 - 1) +
           over_15 * (over_5 - 1) +
           comb(over_5, 2) * (over_3 - 2))
    print(ret)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    solve(N)

if __name__ == '__main__':
    main()