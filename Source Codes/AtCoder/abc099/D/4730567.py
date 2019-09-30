n, c = [int(item) for item in input().split()]
ds = [[int(item) for item in input().split()] for _ in range(c)]
cs = [[int(item) for item in input().split()] for _ in range(n)]

counter = [[0] * (c+1) for _ in range(3)]
for i in range(n):
  for j in range(n):
    counter[(i+j) % 3][cs[i][j]] += 1
    
costs = [[0] * (c+1) for _ in range(3)]
for i in range(1, c+1):
  for j in range(3):
    for k, count in enumerate(counter[j]):
      if k == 0:
        continue
      costs[j][i] += ds[k-1][i-1] * count

ans = 500*500*1000
for i in range(c):
  for j in range(c):
    for k in range(c):
      if i == j or j == k or k == i:
        continue
      sol = costs[0][i+1] + costs[1][j+1] + costs[2][k+1]
      ans = min(ans, sol)
    
print(ans)