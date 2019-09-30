C = int(raw_input())
from fractions import gcd
for case in xrange(1, C + 1):
  ts = [int(t) for t in raw_input().split()[1:]]
  m  = min(ts)
  td = [t - m for t in ts]
  T  = reduce(gcd, td)
  print "Case #" + str(case) + ":", (T-m) % T
