T = int(raw_input())

import math

for case in xrange(1, T+1):
  L, P, C = map(int, raw_input().split())
  target = int(math.ceil(float(P)/L))
  #print case, ":"
  #print L, P, C
  #print target
  ans = 0
  num = C
  #print 't',  ans, num
  while target > num:
    ans += 1
    num *= num
    #print 't',  ans, num
  print "Case #%d: %d" % (case, ans)

