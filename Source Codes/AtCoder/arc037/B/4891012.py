import sys
sys.setrecursionlimit(10000000)

n, m = [int(x) for x in input().split()]
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v = [int(x) for x in input().split()]
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)

def dfs(now, visited):
    loop = now in visited
    visited.add(now)
    while len(adj[now]) > 0:
        nxt = adj[now].pop()
        adj[nxt].remove(now)
        loop = dfs(nxt, visited) or loop

    return loop

visited_all = set()
count = 0
for i in range(n):
    if i in visited_all:
        continue

    visited = set()
    if not dfs(i, visited):
        count += 1

    visited_all |= visited

print(count)