import sys
from heapq import heappop, heappush
readline = sys.stdin.readline
N, M, S = map(int, readline().split())
edges = [[] for _ in [0]*(N+1)]
for _ in [0]*M:
    u, v = map(int, readline().split())
    edges[u].append(v)
    edges[v].append(u)

queue = [(-S, S)]
visited = [0]*(N+1)
result = {S}
r_add = result.add

while queue:
    _min, v = heappop(queue)
    for dest in edges[v]:
        if visited[dest] == 0:
            visited[dest] = 1
            if -dest > _min:
                r_add(dest)
                heappush(queue, (-dest, dest))
            else:
                heappush(queue, (_min, dest))

print("\n".join(map(str, sorted(result))))