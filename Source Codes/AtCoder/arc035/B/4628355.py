n = int(input())
mod = 10**9+7
from collections import defaultdict as ddic
from math import factorial as fac
d = ddic(int)
l = list()
for _ in range(n):
  a = int(input())
  d[a] += 1
  l.append(a)
l.sort()
s = 0
p = 1
for i in range(n):
  s += l[i]*(n-i)
for i in d:
  p *= fac(d[i])
print(s)
print(p%mod)