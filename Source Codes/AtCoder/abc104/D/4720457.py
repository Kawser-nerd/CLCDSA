s = input()

dp = [[0] * (len(s) + 1) for _ in range(4)]
dp[0][0] = 1

for i, c in enumerate(s):
  # use c
  if c == "A" or c == "?":
    dp[1][i+1] = dp[0][i]
  if c == "B" or c == "?":
    dp[2][i+1] = dp[1][i]
  if c == "C" or c == "?":
    dp[3][i+1] = dp[2][i]
  # not use c
  for j in range(4):
    if c == "?":
      dp[j][i+1] += dp[j][i] * 3  
    else:
      dp[j][i+1] += dp[j][i]
    dp[j][i+1] %= 10**9+7
print(dp[-1][-1])