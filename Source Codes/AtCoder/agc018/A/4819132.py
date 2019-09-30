import fractions as fr
from functools import reduce
def gcd(a):
  return reduce(fr.gcd, a)
n, k = map(int, input().split())
a = list(map(int, input().split()))
g = gcd(a)
print("POSSIBLE" if (k in a) or (max(a) >= k and (g == 1 or k%g == 0)) else "IMPOSSIBLE")