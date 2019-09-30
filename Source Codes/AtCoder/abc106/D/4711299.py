n, m, q = [int(item) for item in input().split()]

lr = [[int(item) for item in input().split()] for _ in range(m)]
pq = [[int(item) for item in input().split()] for _ in range(q)]

field = [[0] * (n+1) for _ in range(n+1)]
cumsum = [[0] * (n+1) for _ in range(n+1)]

for item in lr:
  field[item[0]][item[1]] += 1
  
for i in range(1,n+1):
  for j in range(1,n+1):
    cumsum[i][j] = field[i][j] + cumsum[i][j-1]

for i in range(1,n+1):
  for j in range(1,n+1):
    cumsum[i][j] += cumsum[i-1][j]

for p, q in pq:
  print(cumsum[q][q] - cumsum[p-1][q] - cumsum[q][p-1] + cumsum[p-1][p-1])