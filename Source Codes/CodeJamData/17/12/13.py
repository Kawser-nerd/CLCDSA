from heapq import *

def okok(r, q, n):
  return q*10 >= n*r*9 and q*10 <= n*r*11

def compat(i1, i2):
  return (i1[0] < i2[1] and i2[0] < i1[1])

_T = int(raw_input())
for _t in range(1, _T+1):
  N, P = map(int, raw_input().split())
  R = map(int, raw_input().split())
  Q = [map(int, raw_input().split()) for _ in range(N)]

  E = []
  for i in range(N):
    Q[i].sort()
    Rmin, Rmax = 0, 0
    for j in range(P):
      while Q[i][j]*10 >= Rmax*R[i]*9:
        Rmax += 1
      while Q[i][j]*10 > Rmin*R[i]*11:
        Rmin += 1
#      for k in range(Rmin, Rmax):
#        assert(okok(R[i], Q[i][j], k))
      if Rmax > Rmin:
        E.append((Rmin, 1, i, Rmax, j))
        E.append((Rmax, 0, i, Rmin, j))

  E.sort()
  CP = [[] for _ in range(N)]
  C = [0]*N
  used = [[False]*P for _ in range(N)]
  res = 0

  for (r, f, i, e, j) in E:
    if f == 1:
      heappush(CP[i], (e, j))
      C[i] += 1
    else:
      if not used[i][j]:  
        C[i] -= 1
    ok = True
    for i in range(N):
      if C[i] == 0:
        ok = False
        break
    if ok:
      for i in range(N):
        C[i] -= 1
        while used[i][CP[i][0][1]] or CP[i][0][0] <= r:
          heappop(CP[i])
        _, j = heappop(CP[i])
        used[i][j] = True
      res += 1
  print 'Case #{}: {}'.format(_t, res)
