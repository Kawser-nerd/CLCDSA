#! /usr/bin/env python3.2
from functools import lru_cache;

T = int(input())

def load():
  line = [int(x) for x in input().split()]
  x = [line[x] for x in range(0,len(line),2)]
  X = [line[x] for x in range(1,len(line),2)]
  return (x,X)

for t in range(T):
  N, M = (int(x) for x in input().split())
  a, A = load()
  b, B = load()

  @lru_cache(None)
  def get(pa, ua, pb, ub):
    if pa == N or pb == M:
      return 0;
    if A[pa] == B[pb]:
      freeA, freeB = a[pa]-ua, b[pb]-ub
      if freeA <= freeB:
        return freeA + get(pa+1,0,pb,ub+freeA)
      else:
        return freeB + get(pa,ua+freeB,pb+1,0)
    else:
      return max(get(pa+1,0,pb,ub),get(pa,ua,pb+1,0))

  print('Case #', t+1, ': ', get(0,0,0,0), sep='')
  get.cache_clear()
