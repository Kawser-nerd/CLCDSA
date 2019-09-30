def diff(x0, y0, x1, y1):
    return ((x1 - x0) ** 2 + (y1 - y0) ** 2) ** (1 / 2)


def diff_2(x0, y0, x1, y1):
    return (x1 - x0) ** 2 + (y1 - y0) ** 2


x0, y0 = map(int, input().split())
N = int(input())
pX = []
pY = []

for _ in range(N):
    a, b = map(int, input().split())
    pX.append(a)
    pY.append(b)

ret = 100000000

for i in range(N):
    xa = pX[i]
    xb = pX[i + 1] if i + 1 < N else pX[0]
    ya = pY[i]
    yb = pY[i + 1] if i + 1 < N else pY[0]

    a2 = diff_2(x0, y0, xa, ya)
    b2 = diff_2(x0, y0, xb, yb)
    c2 = diff_2(xa, ya, xb, yb)
    m = (a2 - b2 + c2) / 2 / c2
    d = (a2 - m ** 2 * c2) ** (1 / 2)
    ret = min(d, ret)

print(ret)