import math

n = int(input())
for i in range(n):
  a,b = list(map(int,input().split()))
  c = a * b
  r = int(math.sqrt(c))
  if a == b:
    print((r - 1) * 2)
  elif r ** 2 == c:
    print((r - 1) * 2 - 1)
  elif r * (r + 1) < c:
    print((r * 2 - 1))
  else:
    print((r - 1) * 2)