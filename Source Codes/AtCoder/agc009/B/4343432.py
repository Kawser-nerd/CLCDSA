import sys
sys.setrecursionlimit(10**7)

n = int(input())
rev_g = [[] for _ in range(n+1)]
for i in range(n-1):
    a = int(input())
    rev_g[a].append(i+2)

def f(v):
    m = len(rev_g[v])
    if m == 0:
        return 0
    q = []
    for nv in rev_g[v]:
        q.append(f(nv))
    q.sort()
    dp = [0] * (m+1)
    for i in range(m):
        dp[i+1] = max(q[i]+1, dp[i]+1)
    return dp[m]


print(f(1))