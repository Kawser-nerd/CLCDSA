INF = 2**50
def solve(n, m, a):
    c = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
    dp = [-INF] * (n+10)
    dp[0] = 0
    for d in range(n+1):
        for i in range(m):
            nd = d + c[a[i]]
            dp[nd] = max(dp[nd], 10*dp[d] + a[i])
    return dp[n]

n, m = map(int, input().split())
a = list(map(int, input().split()))
print(solve(n, m, a))