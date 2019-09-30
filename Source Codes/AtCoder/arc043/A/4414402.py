n, a, b = map(int, input().split())
s = [int(input()) for _ in range(n)]
t = sum(s)
r = max(s) - min(s)
if r == 0:
  print(-1)
else:
  p = b/r
  q = a - p*t/n
  print(p, q)