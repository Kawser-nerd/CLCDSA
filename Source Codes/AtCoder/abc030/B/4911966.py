n, m = map(int, input().split())
if n > 12:
    n -= 12
N = 360 / 12 * n + 360 / 12 * m / 60
M = 360 / 60 * m
if abs(N - M) <= 180:
    print(abs(N - M))
else:
    print(360 - abs(N - M))