def readint(): return int(raw_input())
def readlist(f): return map(f, raw_input().split())

from math import atan2
from math import pi

dpi = 2*pi

def angle(x1, y1, x2, y2):
  return atan2(y2 - y1, x2 - x1) + pi

def solve():
  N = readint()
  n = N-1
  X, Y = [], []
  for i in range(N):
    x, y = readlist(int)
    X.append(x)
    Y.append(y)
  if n == 0:
    print 0
    return

  for i in range(N):
    l = []
    for j in range(N):
      if i == j: continue
      l.append(angle(X[i], Y[i], X[j], Y[j]))
    l.sort()
    angles = [0.0]
    for k in range(n):
      if l[k] != angles[-1]:
        angles.append((l[k] + angles[-1])/2)
        angles.append(l[k])
      l.append(l[k] + dpi)
    if l[n] == dpi:
      angles.append((l[n] + angles[-1])/2)
    res = n

    a, b = 0, 0
    for ang in angles:
      while l[b] < ang + pi:
        b += 1
      while l[a] <= ang:
        a += 1
      res = min(res, b - a)

    print res


T = readint()
for t in range(T):
  print 'Case #{}:'.format(t+1)
  solve()
