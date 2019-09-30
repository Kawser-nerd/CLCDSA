import sys
import itertools
sys.setrecursionlimit(10000)

tc = int(sys.stdin.readline().strip())

for tmp_tc in xrange(tc):
  [ N ] = map(lambda x: int(x), sys.stdin.readline().strip().split(' '))
  W1 = set(sys.stdin.readline().strip().split(' '))
  W2 = set(sys.stdin.readline().strip().split(' '))
  lines = []
  for n in xrange(2, N):
    lines.append(set(sys.stdin.readline().strip().split(' ')))

  res = None
  for cfg in xrange(1 << (N-2)):
    w1 = set(W1)
    w2 = set(W2)
    for i, line in enumerate(lines):
      if (1 << i) & cfg:
        w1 |= line
      else:
        w2 |= line
    tmp = 0
    for w in w1:
      if w in w2: tmp += 1
    if res == None or tmp < res: res = tmp

  if res == None:
    res = 0
    for w in W1:
      if w in W2: tmp += 1

  print "Case #%d: %d" % (1+tmp_tc, res)

