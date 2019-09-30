#!/usr/bin/env python

import sys, math

lookup = {}

def best(vals):
  repr = str(vals)
  if repr in lookup:
    return lookup[repr]
  elif len(vals) < 2:
    return 0
  elif len(vals) == 2:
    return vals[0] + vals[1]
  else:
    # calc val
    ans = -1
    sum = len(vals) - 2
    for val in vals:
      sum += val
    for i in xrange(1, len(vals)):
      #print 'consider', vals[:i], vals[i:]
      score = best(vals[:i]) + best(vals[i:]) + sum
      if score < ans or ans < 0:
        ans = score
    lookup[repr] = ans
    return ans

cases = int(sys.stdin.readline())

for case_no in xrange(1, cases + 1):
  line = sys.stdin.readline().strip().split()
  P = int(line[0])
  Q = int(line[1])

  positions = [int(val) for val in sys.stdin.readline().strip().split()]
  parts = [positions[0] - 1]
  for i in xrange(1, len(positions)):
    parts.append(positions[i] - positions[i-1] - 1)
  parts.append(P - positions[-1])

  print "Case #%d: %d" % (case_no, best(parts))
  #print lookup
