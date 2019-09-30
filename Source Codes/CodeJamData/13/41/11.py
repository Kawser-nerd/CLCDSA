from sys import stdin

T = int(stdin.readline())
for _ in xrange(1, T+1):
  N, M = map(int, stdin.readline().split())
  orig_cost = 0
  O = []
  E = []
  P = []
  for i in xrange(M):
    o,e,p = map(int, stdin.readline().split())
    O.append(o)
    E.append(e)
    P.append(p)
    k = e - o
    orig_cost += (2*N-k+1)*k*p/2
  pts = list(set(O+E))
  pts.sort()
  K = len(pts)
  count = [0] * K
  for i in xrange(M):
    for j in xrange(K-1):
      if pts[j] >= O[i] and pts[j+1] <= E[i]:
        count[j] += P[i]

  new_cost = 0
  while sum(count) > 0:
    a = 0
    while count[a] == 0: a += 1
    b = a
    while count[b] != 0: b += 1
    m = min(count[a:b])
    for j in xrange(a,b):
      count[j] -= m
    k = pts[b] - pts[a]
    new_cost += (2*N-k+1)*k*m/2
  print 'Case #%d: %d' % (_, (orig_cost - new_cost)%1000002013)
