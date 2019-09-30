import sys


def dfs(v, d, c, e):
    if (dp[v][d] != 0):
        return dp[v][d]

    if (d == 0):
        dp[v][d] = c
        return dp[v][d]

    for u in e[v]:
        dp[u][d-1] = dfs(u, d-1, c, e)

    dp[v][d] = dfs(v, d-1, c, e)
    return dp[v][d]

stdin = sys.stdin

ns = lambda: stdin.readline()
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))

dp = [[0]*11 for i in range(10**5+1)]
e = [[] for i in range(10**5+1)]

N, M = na()
for i in range(M):
    a, b = na()
    a -= 1
    b -= 1
    e[a].append(b)
    e[b].append(a)
    
Q = ni()
qv = [[0,0,0] for i in range(Q)]
for i in range(Q):
    v, d, c = na()
    v -= 1
    qv[Q-1-i][0] = v
    qv[Q-1-i][1] = d
    qv[Q-1-i][2] = c

for i in range(Q):
    dfs(qv[i][0],qv[i][1],qv[i][2],e)

for i in range(N):
    print (dp[i][0])