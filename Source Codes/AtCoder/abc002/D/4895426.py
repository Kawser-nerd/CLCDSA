N, M = map(int,input().split())

X = [[0]*N for _ in range(N)]
for _ in range(M):
  x, y = map(int,input().split())
  x -= 1
  y -= 1
  X[x][y] = 1
  X[y][x] = 1

ans = 1
for i in range(1 << N):
  f = False
  for j in range(N):
    for k in range(j):
      if (i >> j) & (i >> k) & 1 and X[j][k] == 0:
        f = True
        break
    if f:
      break
  if not f:
    ans = max(ans, bin(i).count("1"))
print(ans)