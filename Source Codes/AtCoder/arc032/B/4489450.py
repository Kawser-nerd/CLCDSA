from collections import defaultdict
import sys
sys.setrecursionlimit(sys.getrecursionlimit()*10000)
N, M = map(int, input().split())
g = defaultdict(list)
for i in range(M):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

visited = set()
def dfs(v):
    visited.add(v)
    for c in g[v]:
        if not c in visited:
            dfs(c)

connected_component = 0
for v in range(1, N+1):
    if not v in visited:
        dfs(v)
        connected_component += 1

print(connected_component-1)