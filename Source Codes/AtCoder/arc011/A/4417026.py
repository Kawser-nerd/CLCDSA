m, n, N = map(int, input().split())
d = N
s = N
while d // m:
  s += d//m*n
  d = d%m + d//m*n
print(s)