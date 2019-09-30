from itertools import product
from collections import defaultdict

T = int(raw_input())

for t in xrange(1, T+1):
  M, N = map(int, raw_input().split())
  S = []
  for m in xrange(M):
    S.append(raw_input())
  nodes = 0
  ways = 0
  for comb in product(xrange(N), repeat = M):
    T = []
    for n in xrange(N):
      T.append(set())
    for m in xrange(M):
      s = S[m]
      # print s
      for i in xrange(0, len(s)+1):
        # print s[:i]
        T[comb[m]].add(s[:i])
    cnt = 0
    for n in xrange(N):
      cnt += len(T[n])
    if cnt > nodes:
      ways = 1
      nodes = cnt
    elif cnt == nodes:
      ways += 1
    # print comb
    # print T
  print 'Case #%d: %d %d' % (t, nodes, ways)
