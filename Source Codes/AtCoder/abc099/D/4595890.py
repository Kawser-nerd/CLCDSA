N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
G = [list(map(int, input().split())) for _ in range(N)]
GC = []
GC.append([0]*C)
GC.append([0]*C)
GC.append([0]*C)
for y in range(N):
  for x in range(N):
    GC[(y+x)%3][G[y][x]-1] += 1
ans = 1000000000
for a in range(C):
  for b in range(C):
    if a == b:
      continue
    for c in range(C):
      if a == c or b == c:
        continue
      cost = 0
      for i in range(C):
        cost += GC[0][i]*D[i][a]
        cost += GC[1][i]*D[i][b]
        cost += GC[2][i]*D[i][c]
      ans = min(ans, cost)
print(ans)