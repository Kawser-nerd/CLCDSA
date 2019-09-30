import math

A, B, C = map(int, input().split())


def f(t):
    return A * t + B * math.sin(math.pi * t * C)


lo = 0
hi = 200
count = 0
while count < 100:
    mid = (lo + hi) / 2
    if f(mid) < 100:
        lo = mid
    else:
        hi = mid
    count += 1
print(lo)