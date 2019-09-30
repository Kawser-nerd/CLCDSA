import math
n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())

cost = float('inf')
for i in range(n + 1):
  j = max(
    #math.ceil((- h - b * i + e * (n - i)) / (d + e)),
    (- h - b * i + e * (n - i)) // (d + e) + 1,
    0
  )
  
  if i + j <= n and h + b * i + d * j - (n - i - j) * e > 0:
    cost = min(cost, a * i + c * j)
  #print(cost, i, j)

print(cost)