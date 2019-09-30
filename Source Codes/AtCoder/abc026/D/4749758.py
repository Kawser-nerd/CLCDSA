import math
pi = math.pi
a,b,c = map(int,input().split())
def f(x):
  return a*x + b*math.sin(c*x*pi)
lo = 0
hi = 100
for _ in range(50):
  mid = (lo+hi)/2
  if f(mid) > 100:
    hi = mid
  else:
    lo = mid
print(lo)