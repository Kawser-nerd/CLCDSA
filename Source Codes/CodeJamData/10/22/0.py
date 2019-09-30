f = open('b.in', 'r')
C = int(f.readline())
for t_no in range(1, C + 1):
  dirs = set()
  N, K, B, T = [int(x) for x in f.readline().split()]
  X = [int(x) for x in f.readline().split()]
  V = [int(x) for x in f.readline().split()]
  sol = 0
  for i in range(N - 1, -1, -1):
    if K == 0:
      break
    if (B - X[i]) > T * V[i]:
      sol += K
    else:
      K -= 1
  if K != 0:
    sol = 'IMPOSSIBLE'
  print 'Case #%s: %s' % (t_no, sol)
