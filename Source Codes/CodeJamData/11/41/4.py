def ints():
  return map(int, raw_input().split())

num_cases, = ints()

for case_num in xrange(1, num_cases + 1):
  X, S, R, t, N = ints()
  S = float(S)
  R = float(R)
  walks = []
  for i in xrange(N):
    b, e, w = ints()
    walks.append((w, e-b))
  length = sum(walk[1] for walk in walks)
  walks.append((0, X - length))
  walks.sort()
  total = 0
  for walk in walks:
    ws, wl = walk
    runspeed = ws + R
    walkspeed = ws + S
    runtime = min(t, wl / runspeed)
    total += runtime
    t -= runtime
    rundist = runtime * runspeed
    walkdist = wl - rundist
    walktime = walkdist / walkspeed
    total += walktime
  print "Case #%d: %s" % (case_num, total)
