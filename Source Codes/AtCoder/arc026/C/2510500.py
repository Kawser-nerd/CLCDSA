from heapq import heappop as pop
from heapq import heappush as push

INF = 10 ** 18

class edge:
  def __init__(self, to, cost):
    self.to = to
    self.cost = cost

N, L = map(int,input().split())

G = [[] for i in range(L + 1)]
#G[i]...??i????list?(???????)
d = [INF for i in range(L + 1)]
#d[i]...??????????i???????

def dijkstra(s):
  que = []
  d[s] = 0
  push(que, (0,s))

  while len(que):
    p = pop(que)
    v = p[1]
    if (d[v] < p[0]):
      continue
    for i in range(len(G[v])):
      e = G[v][i]
      if d[e.to] > d[v] + e.cost:
        d[e.to] = d[v] + e.cost
        push(que, (d[e.to], e.to))

for i in range(N):
  l, r, c = map(int,input().split())
  G[l].append(edge(r,c))
for i in range(L):
  G[i + 1].append(edge(i,0))
dijkstra(0)
#print(d)
print(d[L])