#!/usr/bin/python

import os
import sys

def num_ways(H, W, rocks):
  mat = [[0 for c in xrange(W)] for r in xrange(H)]
  isrock = [[False for c in xrange(W)] for r in xrange(H)]
  for (r, c) in rocks:
    isrock[r][c] = True
  mat[0][0] = 1
  for c in xrange(1, W):
    for r in xrange(H):
      if isrock[r][c]:
        continue
      if r >= 1 and c >= 2:
        mat[r][c] += mat[r - 1][c - 2]
      if r >= 2 and c >= 1:
        mat[r][c] += mat[r - 2][c - 1]
      mat[r][c] = mat[r][c]%10007
  return mat[H - 1][W - 1]%10007


def read_data(inf):
  (H, W, R) = [int(x) for x in inf.readline().strip().split()]
  rocks = list()
  for i in xrange(R):
    (r, c) = [int(x) for x in inf.readline().strip().split()]
    rocks.append((r - 1, c - 1))
  return num_ways(H, W, rocks)


N = int(sys.stdin.readline().strip())
for nc in xrange(1, N + 1):
  res = read_data(sys.stdin)
  print "Case #%d: %d" % (nc, res)
