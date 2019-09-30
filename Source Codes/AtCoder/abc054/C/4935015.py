import sys
import collections
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
nsl = lambda: map(str, sys.stdin.readline().split())

n, m = nm()
lis = [[] for i in range(n)]
for i in range(m):
    a, b = nm()
    lis[a - 1].append(b)
    lis[b - 1].append(a)
visited = [0] * n


def dfs(v, n, visited):
    count = 1
    for i in range(n):
        if visited[i] == 0:
            count = 0
    if count == 1:
        return 1
    res = 0
    for i in lis[v]:
        if visited[i - 1] == 1:
            continue
        visited[i - 1] = 1
        res += dfs(i - 1, n, visited)
        visited[i - 1] = 0
    return res


visited[0] = 1
print(dfs(0, n, visited))