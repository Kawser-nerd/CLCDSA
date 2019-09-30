r,c,d = map(int, input().split())
b = d%2
l = 0
a = [list(map(int, input().split())) for _ in range(r)]
for i in range(r):
  for j in range(c):
    if (i+j)%2 == b and i+j <= d and a[i][j] > l:
      l = a[i][j]
print(l)