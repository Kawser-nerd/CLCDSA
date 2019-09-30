n, ma, mb = map(int, input().split())
abc = [tuple(map(int, input().split())) for _ in range(n)]
csup = sum(_abc[2] for _abc in abc) + 1
dp = [[[csup for _ in range(400)] for _ in range(400)] for _ in range(n+1)]
dp[0][0][0] = 0

for i in range(n):
  for _a in range(400):
    for _b in range(400):
      if dp[i][_a][_b] != csup:
        dp[i+1][_a][_b] = min(dp[i+1][_a][_b], dp[i][_a][_b])
        dp[i+1][_a + abc[i][0]][_b + abc[i][1]] = min(dp[i+1][_a + abc[i][0]][_b + abc[i][1]], dp[i][_a][_b] + abc[i][2])

ans = csup
for ai in range(1, 400):
  for bi in range(1, 400):
    if ai * mb == bi * ma:
      ans = min(ans, dp[n][ai][bi])
if ans == csup:
  print(-1)
else:
  print(ans)