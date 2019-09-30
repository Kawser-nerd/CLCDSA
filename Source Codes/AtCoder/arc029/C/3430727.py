import heapq
N,M = map(int,input().split())
es = []
heapq.heapify(es)
for i in range(N):
    c = int(input())
    heapq.heappush(es, (c,0,i+1))
for i in range(M):
    a,b,r = map(int,input().split())
    heapq.heappush(es, (r,a,b))

parent = [i for i in range(N+1)]
rank = [0] * (N+1)
def root(a):
    if parent[a] == a:
        return a
    else:
        parent[a] = root(parent[a])
        return parent[a]
def is_same(a,b):
    return root(a) == root(b)
def unite(a,b):
    ra = root(a)
    rb = root(b)
    if ra == rb: return
    if rank[ra] < rank[rb]:
        parent[ra] = rb
    else:
        parent[rb] = ra
        if rank[ra] == rank[rb]: rank[ra] += 1

ans = e = 0
while e < N:
    cost,a,b = heapq.heappop(es)
    if is_same(a,b): continue
    unite(a,b)
    ans += cost
    e += 1
print(ans)