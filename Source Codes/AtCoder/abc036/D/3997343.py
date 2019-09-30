import sys

sys.setrecursionlimit(10 ** 9)

N = int(input())
graph = [dict() for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1
mod = 10 ** 9 + 7
visited = [False] * N
visited[0] = True


def dfs(v):
    w, b = 1, 1
    for to in graph[v].keys():
        if visited[to]:
            continue
        visited[to] = True
        w_tmp, b_tmp = dfs(to)
        w = (w * (w_tmp + b_tmp)) % mod
        b = (b * w_tmp) % mod

    return w, b


b, w = dfs(0)
print((b + w) % mod)