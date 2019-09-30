N = int(input())
a, b = map(int,input().split())
a -= 1
b -= 1
M = int(input())
e = [[] for _ in range(N)]
for _ in range(M):
  x, y = map(int,input().split())
  e[x-1] += [y-1]
  e[y-1] += [x-1]

dp = [[0 for _ in range(N)] for _ in range(N)]
dp[0][a] = 1
flag = 0
for i in range(N):
  for j in range(N):
    for k in e[j]:
      dp[i+1][k] += dp[i][j]
      if(dp[i+1][b] > 0):
        flag = 1
  if(flag == 1):
    print(dp[i+1][b] % (10**9+7))
    break