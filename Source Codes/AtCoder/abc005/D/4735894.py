# 1 <= N <= 50
N = int(input())

# 1 <= D_ij <= 100
D = list()
for i in range(N):
  D.append(list(map(int, input().split())))


import collections
max_oisi = [0 for i in range(N ** 2 + 1)]
memo = [
  [
    [
      [
        0 for i in range(N + 1)
      ] for j in range(N + 1)
    ] for k in range(N + 1)
  ] for l in range(N + 1)
]
for i in range(1, N + 1):
  for j in range(1, N + 1):
    key = (0, 0, i, j)
    tako = memo[0][0][i-1][j] + memo[0][0][i][j-1] - memo[0][0][i-1][j-1] + D[i-1][j-1]
    memo[0][0][i][j] = tako
    area = i * j
    if tako > max_oisi[area]:
      max_oisi[area] = tako

for k in range(0, N ):
  for l in range(0, N):
    if k == l == 0: continue
    for i in range(k + 1, N + 1):
      for j in range(l + 1, N + 1):
        key = (k, l, i, j)
        tako = memo[0][0][i][j] - memo[0][0][k][j] - memo[0][0][i][l] + memo[0][0][k][l]
        memo[k][l][i][j] = tako
        area = (i - k) * (j - l)
        if tako > max_oisi[area]:
          max_oisi[area] = tako

# 1 <= Q <= N^2
Q = int(input())

# 1 <= p <= N^2
for i in range(Q):
  p = int(input())
  print(max(max_oisi[:p+1]))