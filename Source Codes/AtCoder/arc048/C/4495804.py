import sys
from fractions import gcd
from functools import reduce

N = int(input())
a = sorted(map(int, sys.stdin))
mod = 10**9+7
if N == 1:
    print(pow(2, a[0], mod))
    exit()

gcd = reduce(gcd, [n-a[0] for n in a])
print(pow(2, a[0]+(gcd+1)//2, mod) % mod)