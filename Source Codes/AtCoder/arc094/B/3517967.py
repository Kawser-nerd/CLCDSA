import math
n = int(input())
for i in range(n):
  ans = 0
  a,b = map(int,input().split())
  c = a*b
  d = int(math.sqrt(c))
  if d *d == c:
    d -= 1
  ans += d*2
  if d >= a:
    ans -= 1
  if d >= b:
    ans -= 1
  if (d * (d+1)) >= c:
    ans -= 1
  print(ans)