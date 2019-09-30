from math import sqrt
x, y = map(int, input().split())
N = int(input())
a = [list(map(int, input().split())) for _ in [0]*N]
a += [a[0]]
ans = float("inf")

for (x1, y1), (x2, y2) in zip(a, a[1:]):
    if x1 == x2:
        d = abs(x-x1)
    elif y1 == y2:
        d = abs(y-y1)
    else:
        inc = (y2-y1) / (x2-x1)
        a = inc
        b = -1
        c = -inc*x1 + y1
        d = abs((a*x + b*y + c) / sqrt(a**2+b**2))
    ans = min(ans, d)

print(ans)