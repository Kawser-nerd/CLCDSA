from functools import reduce
from fractions import gcd

N, K = map(int, input().split())
a = list(map(int, input().split()))
g = reduce(gcd, a)

if max(a) >= K and K % g == 0:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")