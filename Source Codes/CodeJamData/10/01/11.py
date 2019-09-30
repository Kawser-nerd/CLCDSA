import sys
inp = sys.stdin

T = int(inp.readline())
for cas in xrange(1, T+1):
  N, K = (int(x) for x in inp.readline().split(' '))
  print "Case #%d:" % (cas),
  mask = (1 << N)-1
  if (K&mask) == mask:
    print "ON"
  else:
    print "OFF"
