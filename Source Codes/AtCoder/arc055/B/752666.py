def read():
  return map(int, input().split())

(N, K) = read()

dp = [[0]*(K+1) for _ in range(2)]

for r in range(N-1, 0, -1):
  dp[r&1][0] = dp[(r+1)&1][0]
  for s in range(1, K+1):
    dp[r&1][s] = dp[(r+1)&1][s] + max(1/N + dp[(r+1)&1][s-1], dp[(r+1)&1][s]) / r

print(max(1/N + dp[1][K-1], dp[1][K]))