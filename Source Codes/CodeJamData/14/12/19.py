def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),
  N = readint()
  adj = [[] for i in range(N)]
  for i in range(N-1):
    a, b = readarray(int)
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)
  best = N-1
  for r in range(N):
    P = [-1]*N
    C = [[] for i in range(N)]
    L = []
    Q = [r]
    while len(Q) > 0:
      i = Q.pop()
      l = True
      for v in adj[i]:
        if v != P[i]:
          P[v] = i
          Q.append(v)
          C[i].append(v)
          l = False
      if l:
        L.append(i)
    keep = [1]*N
    while len(L) > 0:
      i = L.pop()
      if len(C[i]) > 1:
        best1 = -1
        best2 = -1
        for c in C[i]:
          if keep[c] > best1:
            best2 = best1
            best1 = keep[c]
          elif keep[c] > best2:
            best2 = keep[c]
        keep[i] = best1+best2+1
      if P[i] > -1:
        L.append(P[i])
    best = min(best, N-keep[r])
  print best
