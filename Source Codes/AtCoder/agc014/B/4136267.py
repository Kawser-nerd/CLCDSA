N, M = (int(i) for i in input().split())
DP = [False]*N
for i in range(M):
  a, b = (int(k) for k in input().split())
  for j in (a, b):
    DP[j-1] = not DP[j-1]
for i in range(N):
  if DP[i]:
    print('NO')
    break
else:
  print('YES')