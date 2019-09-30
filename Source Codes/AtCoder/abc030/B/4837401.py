n,m = map(int,input().split())
if n >= 12:
    n -= 12
N = 360 * n / 12 + 30 * m / 60
M = 360 * m / 60
if abs(N-M) <= 180:
    print(abs(N-M))
else:
    print(360-abs(N-M))