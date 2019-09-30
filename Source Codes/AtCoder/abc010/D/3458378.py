N, G, E = map(int, input().split())
P = [int(x) for x in input().split()]
R = [[0 for j in range(N + 1)] for i in range(N + 1)]
for i in range(E):
  a, b = map(int, input().split())
  R[a][b] = 1
  R[b][a] = 1
for p in P:
  R[p][N] = 1
def path_find(G, s, t):
  pre = [None] * len(G)
  pre[s] = s
  Q = [s]
  while Q:
    q = Q[0]
    Q = Q[1:]
    if q == t:
      break
    for adv in range(len(G)):
      if G[q][adv] > 0 and pre[adv] == None:
        Q.append(adv)
        pre[adv] = q
  return pre
def ford_fulkerson(G, s, t):
  while True:
    path = path_find(G, s, t)
    if path[t] != None:
      dst = t
      src = path[t]
      c = G[src][dst]
      while path[src] != src:
        dst = src
        src = path[src]
        c = min(G[src][dst], c)
      dst = t
      src = path[t]
      while src != dst:
        G[src][dst] -= c
        G[dst][src] += c
        dst = src
        src = path[src]
    else:
      return G
RR = ford_fulkerson(R, 0, N)
print(sum(RR[N]))