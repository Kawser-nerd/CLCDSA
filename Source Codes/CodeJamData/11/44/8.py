import sys
from Queue import Queue

S = set()
sol = 0

def count(x):
  aux = 0
  while x:
    aux += 1
    x &= x- 1
  return aux

def doit(i, d, mask, used):
  if (i, mask, used) in S:
    return
  S.add((i, mask, used))
  for j in xrange(2, N):
    if A[i][j] and H[j] == d - 1:
      u = used | (1 << j)
      m = mask | T[j]
      m ^= (m & u)
      doit(j, d - 1, m, u)
  if A[i][1]:
    global sol
    if count(mask) > sol:
      sol = count(mask)

T = int(sys.stdin.readline())
for no_t in xrange(1, T + 1):
  N, M = [int(x) for x in sys.stdin.readline().split()]
  A = [[0] * N for x in xrange(N)]
  T = [0 for i in xrange(N)]
  for s in sys.stdin.readline().split():
    x, y = [int(x) for x in s.split(',')]
    A[x][y] = 1
    A[y][x] = 1
    T[x] |= 1 << y
    T[y] |= 1 << x
  H = [-1] * N
  H[1] = 0
  Q = Queue()
  Q.put(1)
  while not Q.empty():
    i = Q.get()
    for j in xrange(N):
      if A[i][j] and H[j] == -1:
        H[j] = H[i] + 1
        Q.put(j)
  S = set()
  sol = 0
  doit(0, H[0], T[0], 1)
  print 'Case #%s: %s %s' % (no_t, H[0] - 1, sol)
