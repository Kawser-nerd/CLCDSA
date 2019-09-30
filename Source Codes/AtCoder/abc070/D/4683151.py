import heapq
N = int(input())
edges = [[] for _ in range(N+1)]
for _ in range(N-1):
    a,b,c = map(int,input().split())
    edges[a].append((b,c))
    edges[b].append((a,c))
Q,K = map(int,input().split())

INF = 10**9 * N
distance = [INF for _ in range(N+1)]
distance[K] = 0
settled = set()
h = [(0,K)]
while len(h) > 0:
    d,v = heapq.heappop(h)
    if v in settled:
        continue
    settled.add(v)
    distance[v] = d
    for (w,a) in edges[v]:
        if distance[v] + a < distance[w]:
            distance[w] = distance[v] + a
            heapq.heappush(h,(distance[w],w))

for _ in range(Q):
    x,y = map(int,input().split())
    ans = distance[x] + distance[y]
    print(ans)