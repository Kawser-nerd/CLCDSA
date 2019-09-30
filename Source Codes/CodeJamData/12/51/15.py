import sys

T = int(sys.stdin.readline())

for t in range(1, T+1):
  n = int(sys.stdin.readline())
  L = map(int, sys.stdin.readline().strip().split())
  P = map(int, sys.stdin.readline().strip().split())

  l = []
  for i, p in enumerate(P):
    if p != 0:
      l.append((float(L[i]) / p, i));
    else:
      l.append((1E30, i));
  l.sort()

  print 'Case #%d: ' % t,
  for p, i in l:
    print i,
  print ''
