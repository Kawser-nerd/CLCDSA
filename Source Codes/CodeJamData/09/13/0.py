#!/usr/bin/python
from sys import stdin

COMB = [[1]]
for i in range(1,45):
  row = [1]
  for j in range(1,i):
    row.append( COMB[i-1][j-1] + COMB[i-1][j] )
  row.append(1)
  COMB.append(row);

def get(n,k):
  if k>=0 and k<=n:
    return COMB[n][k]
  else:
    return 0

T = int(stdin.readline())
for t in range(1,T+1):
  C, N = map(int,stdin.readline().split())

  if N >= C:
    print "Case #%d: 1" % t
    continue

  E = [ 0. ] * (C+1)
  total = 1. * COMB[C][N]
  for c in range(1,C+1):
    change = 0.
    ec = 0.
    for good in range(1,c+1):
      prob = ( 1. * get(c,good) * get(C-c,N-good) ) / total
      change += prob
      ec += prob * E[c-good]
    E[c] = (1 + ec) / change
  print "Case #%d: %.10f" % (t,E[C])
