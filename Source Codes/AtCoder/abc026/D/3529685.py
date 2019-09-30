A,B,C = map(int,input().split())
from math import pi,sin
def f(t):
    return A*t+B*sin(C*pi*t)

l = 0
r = 101
mid = (l+r)/2

for i in range(10**5):
    if f(mid) > 100:
        r = mid
    else:
        l = mid
    mid = (l+r)/2

print(mid)