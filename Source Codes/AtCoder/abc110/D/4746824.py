from math import factorial as fac
from collections import defaultdict as ddict
n,m = map(int,input().split())
d = ddict(int)
ans = 1
mod = 10**9+7
def f2(n,r):
  ret = 1
  for i in range(n,n-r,-1):
    ret *= i
  return ret
def cc(n,r):
  t = min(r,n-r)
  return f2(n,t)//fac(t)
for i in range(2,int(m**.5)+1):
  while m % i == 0:
    d[i] += 1
    m //= i
if m > 1:
  d[m] += 1
for x in d:
  ans = ans * cc(d[x]+n-1,d[x])%mod
print(ans)