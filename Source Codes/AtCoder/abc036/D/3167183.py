from collections import defaultdict
n = int(input())
G = defaultdict(list)
mod = 10 ** 9 + 7
for i in range(n - 1):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

dp = [[0] * 2 for j in range(100005)]


def dfs(v, pre):
    for u in G[v]:
        if u == pre:
            continue
        dfs(u, v)

    f, g = 1, 1
    for u in G[v]:
        if u == pre:
            continue
        g = g * dp[u][1] % mod
        f = f * (dp[u][0] + dp[u][1]) % mod

    dp[v][1] = f
    dp[v][0] = g


dfs(1, -1)
print((dp[1][0] + dp[1][1]) % mod)