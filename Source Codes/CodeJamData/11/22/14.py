import sys
inp = sys.stdin
MAX = 1 << 50

T = int(inp.readline())
for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  parts = inp.readline().strip().split(' ')
  C = int(parts[0])
  D = int(parts[1]) * 2
  points = []
  vends = dict()
  for i in xrange(C):
    parts = inp.readline().strip().split(' ')
    P = int(parts[0]) * 2
    V = int(parts[1])
    points.append(P)
    vends[P] = V
  points.sort()
  lowest = points[0]
  highest = points[-1]
  b = MAX
  l = -1
  while b > 0:
    x = l + b
    target = -(1 << 100)
    ok = True
    for p in points:
      if not ok: break
      for _ in xrange(vends[p]):
        if target < p:
          target = max(target, p - x)
        else:
          if p + x < target:
            ok = False
            break
        target += D
    if not ok:
      l = x
    b >>= 1
  ans = l + 1
  assert ans < MAX / 2
  print "%.1f" % (ans * 0.5)
