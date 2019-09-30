R, B = map(int, input().split())
x, y = map(int, input().split())

pmax = (R + B) // (min(x, y) + 1)
pmin = 0
point = (pmax + pmin) // 2

while True:
    if R >= point and B >= point and (R - point) // (x - 1) + (B - point) // (y - 1) >= point:
        pmin = point
        if pmin == pmax:
            break
        point = (pmax + point + 1) // 2
    else:
        pmax = point -1
        if pmin == pmax:
            break
        point = (pmin + point) // 2

print(pmin)