#!/usr/bin/env python

import sys, math

cases = int(sys.stdin.readline())

for case_no in xrange(1, cases + 1):
  ans = 0
  base = 2
  chars = sys.stdin.readline().strip()
  conv = {}
  cur = 1
  num = []
  for char in chars:
    if char not in conv:
      conv[char] = cur
      if cur == 1:
        cur = 0
      elif cur == 0:
        cur = 2
      else:
        cur += 1
    num.append(conv[char])
  if cur < 2:
    base = 2
  else:
    base = cur
  
  pow = 0
  for val in num[::-1]:
    ans += val * (math.pow(base, pow))
    pow += 1

  print "Case #%d: %d" % (case_no, ans)
