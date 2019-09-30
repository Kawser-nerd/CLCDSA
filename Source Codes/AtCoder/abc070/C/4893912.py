N=int(input())
Tn = [int(input()) for _ in range(N)]

import fractions
def lcm(a, b):
    return a*b // fractions.gcd(a, b)

from functools import reduce
print(reduce(lcm, Tn, 1))