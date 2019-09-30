import sys
input = sys.stdin.readline

import math

a, b, c = map(int, input().split())

def f(t):
    return a * t + b * math.sin(c*t*math.pi)

left = 0
right = 10000

while abs(f(right) - 100) > 10 ** (-6):
    mid = (left + right) / 2
    f_mid = f(mid)
    if f_mid >= 100:
        right = mid
    else:
        left = mid

print(right)