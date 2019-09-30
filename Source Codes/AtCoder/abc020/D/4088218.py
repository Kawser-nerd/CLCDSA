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
    from collections import Counter
    from itertools import product
    from functools import reduce
    from operator import mul

    N, K = map(int, input().split())
    mod = 10**9+7
    if K == 1:
        print(N*(N+1)//2 % mod)
        exit()
    divisors = Counter()

    _K = K
    primes = get_prime_set(int(sqrt(K))+1)
    for p in filter(lambda x: _K % x == 0, primes):
        while _K % p == 0:
            divisors[p] += 1
            _K //= p
    if _K > 1:
        divisors[_K] = 1

    ans = 0
    for prime_factors, exp_ub in [zip(*divisors.items())]:
        for exp_lb in product(*(range(e+1) for e in exp_ub)):
            subtotal, exp_lb_sum = 0, sum(exp_lb)
            for exp_current in product(*(range(lb, min(lb+1, ub)+1) for lb, ub in zip(exp_lb, exp_ub))):
                gcd = reduce(mul, (p ** e for p, e in zip(prime_factors, exp_current)))
                count = N // gcd
                sign = (-1 if (sum(exp_current) - exp_lb_sum) % 2 else 1)
                subtotal += ((gcd + gcd * count) * count // 2) * sign
            gcd = reduce(mul, (p ** e for p, e in zip(prime_factors, exp_lb)))
            ans += subtotal * K // gcd

    print(ans % mod)