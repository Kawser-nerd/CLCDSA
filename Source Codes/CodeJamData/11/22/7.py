for case in xrange(1, int(raw_input())+1):
  C, D = map(int, raw_input().split())
  points = [map(int, raw_input().split()) for _ in xrange(C)]

  l, r = 0.0, 2e6*D
  for _ in xrange(1000):
    m = (l+r)/2
    p = points[0][0] - m
    possible = True

    for point in points:
      p = max(p, point[0]-m)
      last_p = p+D*(point[1]-1)
      limit_p = point[0]+m
      if last_p > limit_p:
        possible = False
        break
      p = last_p + D

    if possible:
      r = m
    else:
      l = m

  print "Case #%d: %.2f" % (case, l)
