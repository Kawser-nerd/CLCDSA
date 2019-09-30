R, B = map(int, input().split())
x, y = map(int, input().split())

if R / x < B / y:
    R, B = B, R
    x, y = y, x

pmin = R // x
if B <= pmin:
    pmin = B
    pmax = B
else:
    pmax = pmin + (B - pmin) // y
    point = (pmax + pmin) // 2

while pmin < pmax:
    if (R - point) // (x - 1) + (B - point) // (y - 1) >= point:
        pmin = point
        point = (pmax + point + 1) // 2
    else:
        pmax = point - 1
        point = (pmin + point) // 2

print(pmin)