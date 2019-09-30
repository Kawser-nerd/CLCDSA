import sys

intersections = None
corners = None
N = None
M = None

def GoNS(y, x, time):
  (s, w, t) = intersections[y][x]
  time = time - t
  time = time % (s + w)
  if time <= s - 1:
    return 1
  else:
    return (s - time) + w + 1

def GoEW(y, x, time):
  (s, w, t) = intersections[y][x]
  time = time - t + w
  time = time % (s + w)
  if time <= w - 1:
    return 1
  else:
    return (w - time) + s + 1

def MaybeSet(y, x, newtime):
  corner = corners[y][x]
  if corner == None or corner > newtime:
    corners[y][x] = newtime
    Flow(y, x)

def Flow(y, x):
  mytime = corners[y][x]
  if y > 0:
    if y % 2 == 0:
      MaybeSet(y - 1, x, mytime + 2)
    else:
      MaybeSet(y - 1, x, mytime + GoNS(y/2, x/2, mytime))
  if y < (N * 2 - 1):
    if y % 2 == 1:
      MaybeSet(y + 1, x, mytime + 2)
    else:
      MaybeSet(y + 1, x, mytime + GoNS(y/2, x/2, mytime))
  if x > 0:
    if x % 2 == 0:
      MaybeSet(y, x - 1, mytime + 2)
    else:
      MaybeSet(y, x - 1, mytime + GoEW(y/2, x/2, mytime))
  if x < (M*2-1):
    if x % 2 == 1:
      MaybeSet(y, x + 1, mytime + 2)
    else:
      MaybeSet(y, x + 1, mytime + GoEW(y/2, x/2, mytime))

def Handle():
  global intersections, corners, N, M
  (N, M) = map(lambda x: int(x), sys.stdin.readline().strip().split(" "))
  intersections = []
  for row in xrange(0, N):
    line = map(lambda x: int(x), sys.stdin.readline().strip().split(" "))
    row_intersections = []
    for col in xrange(0, M):
      row_intersections.append(line[:3])
      line = line[3:]
    intersections.append(row_intersections)
  corners = [[None for x in xrange(0, M*2)] for x in xrange(0, N*2)]
  corners[N*2 - 1][0] = 0
  Flow(N*2 - 1, 0)
  print >>sys.stderr, "map:"
  for row in xrange(0, N*2):
    for col in xrange(0, M*2):
      print >>sys.stderr, corners[row][col],
    print >>sys.stderr
  return corners[0][M*2 - 1]

C = int(sys.stdin.readline().strip())

for i in xrange(0, C):
  x = Handle()
  print "Case #%d: %d" % (i + 1, x)
  print >>sys.stderr, "Case done", i + 1

