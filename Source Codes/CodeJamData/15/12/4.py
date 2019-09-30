def readint(): return int(raw_input())
def readlist(f): return map(f, raw_input().split())

from fractions import gcd

def solve():
  B, N = readlist(int)
  M = readlist(int)

  if N <= B:
    return N

  a, b = 0, max(M) * N
  while a+1 < b:
    m = (a + b)/2
    s = 0
    for t in M:
      s += m / t + 1
    if s < N:
      a = m
    else:
      b = m

  sa, sb = 0, 0
  for t in M:
    sa += a / t + 1
    sb += b / t + 1
  for i in range(B):
    if b % M[i] == 0:
      sa += 1
      if sa == N: return (i+1)

T = readint()
for t in range(T):
  print 'Case #{}: {}'.format(t+1, solve())
