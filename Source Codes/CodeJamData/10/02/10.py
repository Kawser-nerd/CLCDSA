#!/usr/bin/python
from sys import stdin

def gcd(x,y):
  while y != 0: x, y = y, x%y
  return x

C = int(stdin.readline())
for c in range(1,C+1):
  line = [ int(x) for x in stdin.readline().split() ]
  N, line = line[0], line[1:]
  diffs = []
  for n in range(N-1): diffs.append( abs(line[n+1] - line[n]) )
  T = reduce( gcd, diffs )
  offset = line[0] % T
  if offset > 0: offset = T - offset
  print "Case #%d: %d" % (c,offset)
