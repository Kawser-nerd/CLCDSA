#!/usr/bin/env python

import sys

cases = int(sys.stdin.readline())

text = 'welcome to code jam'
ref = {}
for i in xrange(len(text) - 1, -1, -1):
  if text[i] in ref:
    ref[text[i]].append(i)
  else:
    ref[text[i]] = [i]

case = 1
for line in sys.stdin:
  vals = [1]
  vals += [0 for c in text]
  for c in line.strip():
    if c in ref:
      for pos in ref[c]:
        vals[pos + 1] += vals[pos]
        vals[pos + 1] %= 10000
  print 'Case #%d:' % case,
  ans = vals[-1] % 10000
  if ans < 10:
    print '000' + str(ans)
  elif ans < 100:
    print '00' + str(ans)
  elif ans < 1000:
    print '0' + str(ans)
  else:
    print str(ans)
  case += 1
