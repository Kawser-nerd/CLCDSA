n, k = map(int, input().split())
from operator import mul
from functools import reduce
mod = 10**9+7
def cmb(n,r):
    r = min(n-r,r)
    if r == 0: return 1
    over = reduce(mul, range(n, n - r, -1))
    under = reduce(mul, range(1,r + 1))
    return over // under

if n > k:
  print(cmb(n+k-1,k)%mod)
else:
  t = k%n
  print(cmb(n,t)%mod)