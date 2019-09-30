#!/usr/bin/env python3

from sys import stdin
from fractions import gcd	# math.gcd is introduced by python 3.5
from functools import reduce

def lcm(x, y):
  """The least common multiple of x and y."""
  return x * (y // gcd(x, y))

def tuples(m, N):
  """
  List of list of m'-tuples over {1,2,3,...,N} for 0 <= m' <= m.
  Every m-tuple does not contain a multiple of some j in the tuple.
  The lcm of the m-tuple is less than or equal to N.
  """
  if m == 0: return [[()]]
  ts = tuples(m - 1, N)
  if len(ts[-1]) == 0: return ts

  ls = []
  for t in ts[-1]:
    lc = reduce(lcm, t) if len(t) > 0 else 1
    mi = min(t)         if len(t) > 0 else N + 1
    for i in range(mi - 1, 0, -1):
      if any(j % i == 0 for j in t): continue
      if lcm(lc, i) > N: continue
      ls.append((i,) + t)
  ts.append(ls)
  return ts

def value(a, t):
  """
  Total value of the jewels that are labeled a multiple of x
  for some x in t.
  """
  used = [False for i in a]
  v = 0
  for x in t:
    for i in range(x - 1, len(a), x):
      if not used[i]:
        v = v + a[i]
        used[i] = True
  return v

def remove(a, t):
  """
  Break all jewels that are labeled a multiple of x for some x in t.
  """
  for x in t:
    for i in range(x - 1, len(a), x):
      a[i] = 0

def flatten(ls):
  """Flatten a list of lists."""
  return [x for l in ls for x in l]

def solve(a):
  n = len(a)
  tl = flatten(tuples(n, n))
  tl.sort(key=lambda t: [-x for x in t])
  for t in tl:
    if value(a, t) < 0: remove(a, t)
  return sum(a)

N = int(stdin.readline())
a = [int(w) for w in stdin.readline().split()]
if len(a) != N: raise
print(solve(a))