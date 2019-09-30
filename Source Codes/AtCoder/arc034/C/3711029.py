def get_prime_set(ub):
    from itertools import chain
    from math import sqrt

    if ub < 4:
        return ({}, {}, {2}, {2, 3})[ub]

    ub, ub_sqrt = ub+1, int(sqrt(ub))+1
    primes = {2, 3} | set(chain(range(5, ub, 6), range(7, ub, 6)))
    du = primes.difference_update
    for n in chain(range(5, ub_sqrt, 6), range(7, ub_sqrt, 6)):
        if n in primes:
            du(range(n*3, ub, n*2))

    return primes


if __name__ == "__main__":
    from math import sqrt
    from collections import defaultdict
    from functools import reduce
    from operator import mul

    A, B = map(int, input().split())
    primes = sorted(get_prime_set(int(sqrt(A))))
    divisors = defaultdict(int, {1: 0})

    for num in range(B + 1, A + 1):
        for p in primes:
            while num % p == 0:
                divisors[p] += 1
                num //= p
        if num > 1:
            divisors[num] += 1

    print(reduce(mul, [k+1 for k in divisors.values()]) % (10**9+7))