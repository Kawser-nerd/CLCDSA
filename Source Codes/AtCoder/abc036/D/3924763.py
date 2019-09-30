import sys
sys.setrecursionlimit(10**6)

N = int(input())
edges = [[] for _ in [0]*N]
for a, b in (map(int, l.split()) for l in sys.stdin):
    edges[a-1].append(b-1)
    edges[b-1].append(a-1)

mod = 10**9+7
dp = [[0, 0] for _ in [0]*N]

def dfs_w(from_v, v):
    if not dp[v][0]:
        dp[v][0] = 1
        for to_v in edges[v]:
            if to_v != from_v:
                dp[v][0] = (dp[v][0] * (dfs_w(v, to_v)+dfs_b(v, to_v))) % mod
    return dp[v][0]

def dfs_b(from_v, v):
    if not dp[v][1]:
        dp[v][1] = 1
        for to_v in edges[v]:
            if to_v != from_v:
                dp[v][1] = (dp[v][1] * dfs_w(v, to_v)) % mod
    return dp[v][1]

print((dfs_w(-1, 0) + dfs_b(-1, 0)) % mod)