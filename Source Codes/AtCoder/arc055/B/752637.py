import sys

def read():
  return map(int, input().split())

(N, K) = read()

if N == 1:
  print(1)
  sys.exit()

dp = [[0]*(K+1) for _ in range(2)]

dp[(N-1)&1][0] = 0
for s in range(1, K+1):
  dp[(N-1)&1][s] = 1/N/(N-1)

for r in range(N-2, 0, -1):
  dp[r&1][0] = dp[(r+1)&1][0]
  for s in range(1, K+1):
    dp[r&1][s] = dp[(r+1)&1][s] + max(1/N + dp[(r+1)&1][s-1], dp[(r+1)&1][s]) / r

result = max(1/N + dp[1][K-1], dp[1][K])

print(result)