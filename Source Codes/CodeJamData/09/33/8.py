#!/usr/bin/env python
from sys import stdin

memo = {}

def computeBruteM(a,b, releases, rleft, rright):
  key = (a,b,rleft,rright)
  if key not in memo:
    memo[key] = computeBrute(a,b,releases,rleft,rright)
  return memo[key]
    

def computeBrute(a, b, releases, rleft, rright):
  if len(releases) == 0:
    return 0
  if rleft >= rright:
    return 0
  assert a < b
  pays = []
  for idx in range(rleft,rright):
    cell = releases[idx]
    pay = b - a - 1
    if rleft != idx:
      pay += computeBruteM(a, cell, releases, rleft, idx)
    if rright != idx+1:
      pay += computeBruteM(cell+1, b, releases, idx+1, rright)
    pays.append(pay)
  return min(pays)

import psyco
psyco.full()

caseCount = int(stdin.readline())

for caseNo in xrange(1, caseCount+1):
  p,q = [int(x) for x in stdin.readline().strip().split()]
  releases = [int(x)-1 for x in stdin.readline().strip().split()]
  releases.sort()
  memo = {}
  result = computeBruteM(0, p, releases, 0, len(releases))
  print "Case #%d: %d"%(caseNo, result)

