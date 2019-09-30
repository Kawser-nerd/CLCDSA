#!/usr/bin/env python3
import sys
import math
import collections
import itertools
INF = float("inf")


def trial_division_sqrt(n):
    prime_count = collections.Counter()

    for i in range(2, int(math.sqrt(n)) + 2):
        while n % i == 0:
            n /= i
            prime_count[i] += 1
    if n > 1:
        prime_count[int(n)] += 1

    return prime_count


def eratosthenes_sieve(n):
    table = [0] * (n + 1)
    prime_list = []

    for i in range(2, n + 1):
        if table[i] == 0:
            prime_list.append(i)
            for j in range(i + i, n + 1, i):
                table[j] = 1

    return prime_list


def solve(N: int):
    primes = eratosthenes_sieve(N)

    pc = collections.Counter()
    for n in range(1, N+1):
        pc += trial_division_sqrt(n)
    ans = 0

    for p in itertools.combinations(primes, 3):
        # 2 4 4
        if pc[p[0]] >= 2 and pc[p[1]] >= 4 and pc[p[2]] >= 4:
            ans += 1
        # 4 2 4
        if pc[p[0]] >= 4 and pc[p[1]] >= 2 and pc[p[2]] >= 4:
            ans += 1
        # 4 4 2
        if pc[p[0]] >= 4 and pc[p[1]] >= 4 and pc[p[2]] >= 2:
            ans += 1

    for p in itertools.combinations(primes, 2):
        # 2 24
        if pc[p[0]] >= 2 and pc[p[1]] >= 24:
            ans += 1
        # 24 2
        if pc[p[0]] >= 24 and pc[p[1]] >= 2:
            ans += 1

        if pc[p[0]] >= 4 and pc[p[1]] >= 14:
            ans += 1
        if pc[p[0]] >= 14 and pc[p[1]] >= 4:
            ans += 1

    for p in primes:
        if pc[p] >= 74:
            ans += 1

    print(ans)
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