from math import sin, pi
A, B, C = map(int, input().split())


def f(t):
    return A * t + B * sin(C * t * pi)


eps = 1e-6
low, high = 0, 200
while f(high) - 100 > eps:
    mid = (high + low) / 2
    ret = f(mid)
    if ret < 100:
        low = mid
    else:
        high = mid

print(high)