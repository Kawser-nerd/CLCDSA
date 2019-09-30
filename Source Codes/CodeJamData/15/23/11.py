import sys

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  hikers = []
  for _n in xrange(N):
    [ D, H, M ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
    for h in xrange(H):
      hikers.append((D, M+h))
  res = 0
  if len(hikers) == 2:
    [ (d1, m1), (d2, m2) ] = hikers
    t1 = m1 * (360 - d1)
    t2 = m2 * (360 - d2)
    if t1 < t2: # 1 finishes first
      if m1 * d1 + t2 >= 720 * m1: res = 1
      else: res = 0
    else:
      if m2 * d2 + t1 >= 720 * m2: res = 1
      else: res = 0
  print "Case #%d: %d" % (tmp_tc + 1, res)
