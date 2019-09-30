import heapq

_T = int(raw_input())
for _t in range(1, _T+1):

  N, S = map(int, raw_input().split())
  A = []
  for _ in range(N):
    A.append(map(int, raw_input().split()))

  V = [False]*N
  D = [0.0]*N
  Q = []
  Q.append((0.0, 0))

  while not V[1]:
    (d, i) = heapq.heappop(Q)
    D[i] = d
    V[i] = True
    for j in range(N):
      if V[j]: continue
      dx = A[i][0] - A[j][0]
      dy = A[i][1] - A[j][1]
      dz = A[i][2] - A[j][2]
      dd = (dx*dx + dy*dy + dz*dz)**0.5
      nd = max(d, dd)
      heapq.heappush(Q, (nd, j))

  res = D[1]
  print 'Case #{}: {}'.format(_t, res)
