import heapq

K = int(input())
adj = [dict() for i in range(K)]
for i in range(1, K):
  adj[i] = dict()
  adj[i][(i+1)%K] = 1
  adj[i][(i*10)%K] = 0

def dijkstra(adj):
  q = []# p q
  d = dict()# min cost from start
  p = dict()# parent node
  n = len(adj)# num of node

  for i in range(n):
    d[i] = float('inf')

  start_id = 1
  d[start_id] = 0
  heapq.heappush(q, (0, start_id))
  S = set()

  while len(S) != n:
    dist, node_id = heapq.heappop(q)
    S.add(node_id)
    for u, c in adj[node_id].items():
      if c + d[node_id] < d[u]:
        d[u] = c + d[node_id]
        heapq.heappush(q, (d[u], u))

  return d

d = dijkstra(adj)
print(d[0]+1)