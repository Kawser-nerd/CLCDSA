N, M = map(int, input().split())
G = [[] for i in range(N)]
for i in range(M):
  a, b = map(int, input().split())
  G[a - 1].append(b - 1)
  G[b - 1].append(a - 1)
V = []
D = 0
for i in range(N):
  if len(G[i]) % 2:
    print('No')
    break
  D = max(len(G[i]), D)
  if len(G[i]) == 4:
    V.append(i)
else:
  if D >= 6:
    print('Yes')
  elif len(V) != 2:
    print('Yes' if len(V) > 2 else 'No')
  else:
    s = V[0]
    for i in range(3):
      t = G[s].pop()
      G[t].pop(G[t].index(s))
      while t not in V:
        d = G[t].pop()
        G[d].pop(G[d].index(t))
        t = d
      if s == t:
        print('Yes')
        break
      else:
        s = t
    else:
      print('No')