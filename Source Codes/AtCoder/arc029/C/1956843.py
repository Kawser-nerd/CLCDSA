from heapq import heappush, heappop

N, M = map(int, input().split())
parent = [i for i in range(N+1)] # 0th city is market
rank = [1] * (N+1)

roads = []
for i in range(1, N+1):
  heappush(roads, (int(input()), 0, i))
for i in range(M):
  a, b, r = map(int, input().split())
  heappush(roads, (r, a, b))

# Union-Find
def get_root(node):
  global parent
  if parent[node] == node:
    return node
  root = get_root(parent[node])
  parent[node] = root
  return root

def is_group(a, b):
  return get_root(a) == get_root(b)

def union(a, b):
  global rank
  root_a = get_root(a)
  root_b = get_root(b)
  rank_a = rank[root_a]
  rank_b = rank[root_b]
  if rank_a < rank_b:
    parent[root_a] = root_b
  else:
    parent[root_b] = root_a
    if rank_a == rank_b:
      rank[root_a] += 1

# Kruskal's
ans = 0
for i in range(len(roads)):
  cost, a, b = heappop(roads)
  if is_group(a, b):
    continue
  union(a, b)
  ans += cost

print(ans)