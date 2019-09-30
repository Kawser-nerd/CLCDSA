import sys

sys.setrecursionlimit(10 ** 9)

N = int(input())
graph = [dict() for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    graph[a - 1][b - 1] = 1
    graph[b - 1][a - 1] = 1
mod = 10 ** 9 + 7
dp = [[0] * 2 for _ in range(N)]


def dfs_w(from_v, v):
    if dp[v][0] == 0:
        dp[v][0] = 1
        for to in graph[v].keys():
            if to != from_v:
                dp[v][0] = dp[v][0] * (dfs_w(v, to) + dfs_b(v, to))
                dp[v][0] %= mod

    return dp[v][0]


def dfs_b(from_v, v):
    if dp[v][1] == 0:
        dp[v][1] = 1
        for to in graph[v].keys():
            if to != from_v:
                dp[v][1] = dp[v][1] * dfs_w(v, to)
                dp[to][1] %= mod
    return dp[v][1]


print((dfs_b(-1, 0) + dfs_w(-1, 0)) % mod)