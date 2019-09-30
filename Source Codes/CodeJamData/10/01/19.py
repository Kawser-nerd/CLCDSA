#!/usr/bin/python
import sys

sys.stdin.readline()
t=0
for line in sys.stdin:
  if line.strip()=="":
    continue
  v = map(int, line.strip().split(" "))
  m = (1<<v[0])-1
  t += 1
  r = ["OFF","ON"][v[1]&m==m]
  print "Case #%d: %s" % (t, r)

