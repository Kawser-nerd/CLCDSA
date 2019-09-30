import sys

tc = int(sys.stdin.readline())
for tmp_tc in xrange(tc):
  [ R, C, NN ] = map(lambda x: int(x), sys.stdin.readline().split(' '))
  res = None
  if NN == 0: res = 0
  else:
    for bt in [ 0, 1 ]:
      N = NN
      q, ns = 0, [ 0 ] * 5
      for x in xrange(R):
        for y in xrange(C):
          if (x+y) % 2 == bt: q += 1
          else:
            w = 4
            if x == 0: w -= 1
            if x == R-1: w -= 1
            if y == 0: w -= 1
            if y == C-1: w -= 1
            ns[w] += 1
      tmp = 0
      N -= q
      for i, n in enumerate(ns):
        if 0 < N:
          tmp += i * min(N, n)
          N -= n
      if res == None or tmp < res:
        res = tmp
  print "Case #%d: %d" % (tmp_tc + 1, res)
