import sys
import os
def myabs(a):
  if (a < 0): return -a
  else: return a

lines = open("a2.in", "r").readlines()
t = int(lines[0].strip())
for ti in range(1,t+1):
  items = lines[ti].strip().split(" ")
  n = int(items[0])
  o = 1
  b = 1
  o_t = 0
  b_t = 0
  for i in range(n):
    order_k = items[i*2 + 1]
    order_i = int(items[i*2 + 2])
    if (order_k == "O"):
      o_t += myabs(o-order_i)
      o = order_i
      if (o_t < b_t): o_t = b_t
      o_t = o_t + 1
    else:
      b_t += myabs(b-order_i)
      b = order_i
      if (b_t < o_t): b_t = o_t
      b_t = b_t + 1
  ans = 0
  if (o_t > b_t): ans = o_t
  else: ans = b_t
  print "Case #%d: %d" % (ti, ans)
