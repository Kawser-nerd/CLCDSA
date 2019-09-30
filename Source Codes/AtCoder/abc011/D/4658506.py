n, d = map(int, input().split())
x, y = map(int, input().split())
C = [[0 for j in range(n+1)] for i in range(n+1)]
C[0][0] = 1
for i in range(1, n+1):
  C[i][0] = C[i-1][0] / 2
  for j in range(1, i+1):
    C[i][j] = (C[i-1][j-1] + C[i-1][j]) / 2
ans = 0
for i in range(n+1):
  for j in range(n+1):
    k = (i*d - x) // d
    l = (j*d - y) // d
    if 0<=k<=n and 0<=l<=n and (i-k)*d==x and (j-l)*d==y and i+j+k+l==n:
      ans += C[n][i+k] * C[i+k][i] * C[j+l][j]
print(ans)