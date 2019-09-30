#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import math, os, sys, random


class Wall(object):
  def __init__(self):
    self.W = []
    self.E = []
  
  def __getitem__(self, i):
    if i < 0:
      j = -i - 1
      if j >= len(self.W): return 0
      else: return self.W[j]
    else:
      if i >= len(self.E): return 0
      else: return self.E[i]
  
  def __setitem__(self, i, v):
    if i < 0:
      j = -i - 1
      while j >= len(self.W): self.W.append(0)
      self.W[j] = v
    else:
      while i >= len(self.E): self.E.append(0)
      self.E[i] = v
  
  def __repr__(self):
    return '[%d:%d]->%s' % (min(0, -len(self.W)), max(0, len(self.E) - 1), str(self.W[::-1]+self.E))


def single_test(IN, OUT):
  N = int(IN.readline())
  attacks_by_time = []
  for i in range(N):
    d, n, w, e, s, dd, dp, ds = map(int, IN.readline().split())
    for j in range(n):
      attacks_by_time.append((i + 1, d, (w, e), s))
      d += dd
      w += dp
      e += dp
      s += ds
  attacks_by_time.sort(key = lambda a: a[1])
  
  W = Wall()
  
  od = attacks_by_time[0][1] - 1
  queue = []
  result = 0
  
  for a in attacks_by_time:
    od = d
    d = a[1]
    if d > od:
      for q in queue:
        W[q[0]] = max(W[q[0]], q[1])
      queue = []
    success = False
    for i in range(a[2][0], a[2][1]):
      if W[i] < a[3]:
        success = True
        queue.append((i, a[3]))
    if success:
      result += 1
  
  return result
  


def main(IN, OUT):
  T = int(IN.readline())
  for i in range(1, T+1):
    OUT.write('Case #%d: %d\n' % (i, single_test(IN, OUT)))


if __name__ == '__main__':
  assert len(sys.argv) == 2
  IN = open(sys.argv[1], 'rt')
  OUT = open('%s.out' % sys.argv[1][:-3], 'wt')
  main(IN, OUT)
  OUT.close()
  IN.close()

