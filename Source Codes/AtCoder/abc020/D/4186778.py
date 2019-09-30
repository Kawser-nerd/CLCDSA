from itertools import product
from functools import reduce
import operator

mod = int(1e9 + 7)
n, k = map(int, input().split())

ps = []
_ = k
for i in range(2, int(k**0.5) + 1):
    if _ % i == 0: ps.append(i)
    while _ % i == 0: _ //= i
if 1 < _: ps.append(_)

def factorize(x):
    r = []
    for p in ps:
        if x % p == 0: r.append([0, p])
        while x % p == 0:
            r[-1][0] += 1
            x //= p
    return r

def factors(x):
    pes = factorize(x)
    pfs = list(map(lambda pe: list(map(lambda e: pe[1]**e, [i for i in range(pe[0] + 1)])), pes))
    pds = list(product(*pfs))
    fcs = list(map(lambda u: reduce(operator.mul, u, 1), pds))
    return fcs

def mu(x):
    f = factorize(x)
    if list(filter(lambda u: 1 < u[0], f)): return 0
    return (-1)**len(f)

s = 0
for f in factors(k):
    for d in factors(f):
        get_sum_multiple_of = lambda d: (1 + (n // d)) * (n // d) // 2
        s += mu(d) * d * get_sum_multiple_of(f)
        s %= mod

ans = s * k % mod
if ans < 0: ans += mod
print(ans)