from math import pi, sin

A, B, C = map(int, input().split())

def f(t):
    return A * t + B * sin(C*t*pi)

low = 0
high = 200

for i in range(100):
    mid = (low + high)/2
    if f(mid) < 100: low = mid
    else: high = mid
print(low)