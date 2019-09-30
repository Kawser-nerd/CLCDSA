cases = int(raw_input())

for case in xrange(1, cases + 1):
  n = int(raw_input())
  vals = [ int(t) for t in raw_input().split() ]

  a = 0
  b = 0
  speed = 0

  for i in xrange(1, n):
    c, d = vals[i-1], vals[i]
    speed = max(speed, c - d)
    a += max(c - d, 0)

  for i in xrange(n - 1):
    b += min(speed, vals[i])

  print "Case #%d: %d %d" % (case, a, b)
