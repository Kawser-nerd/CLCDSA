import sys
sys.setrecursionlimit(10**6)
N, K = map(int, input().split())

dp = [[[-1, -1] for _ in [0]*(K+2)] for _ in [0]*(N+1)]
for i in range(K+1):
    dp[N][i] = [0, 0]
dp[N][K][1] = 1
for i in range(N+1):
    dp[i][K+1] = [0, 0]


def solve(i, j, b):
    if dp[i][j][b] == -1:
        max_prob, not_max_prob = 1/(i+1), 1-1/(i+1)
        if N-i+j == K:
            dp[i][j][b] = solve(i+1, j+1, b)*not_max_prob + solve(i+1, j+1, 1)*max_prob
        else:
            dp[i][j][b] = solve(i+1, j, b)*not_max_prob + max(solve(i+1, j+1, 1), solve(i+1, j, 0))*max_prob
    return dp[i][j][b]


print(solve(0, 0, 0))