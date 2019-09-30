from functools import reduce
from fractions import gcd
n, k = map(int, input().split())
a = list(map(int, input().split()))
print('POSSIBLE' if k % reduce(gcd, a) == 0 and max(a) >= k else 'IMPOSSIBLE')