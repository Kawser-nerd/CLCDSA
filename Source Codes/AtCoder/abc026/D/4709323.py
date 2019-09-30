import math
a, b, c = map(int, input().split())
high = 2 * ((100-b)//(2*a)+1)
low = 0
for _ in range(1000):
  mid = (high + low) / 2
  if a*mid + b*math.sin(c*math.pi*mid) - 100 > 0:
    high = mid
  else:
    low = mid
print(high)