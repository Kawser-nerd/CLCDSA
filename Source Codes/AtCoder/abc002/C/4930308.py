xa, ya, xb, yb, xc, yc = map(int, input().split())
xb = xb - xa
yb = yb - ya
xc = xc - xa
yc = yc - ya
xa = 0
ya = 0

S = abs(xb * yc - yb * xc) / 2
print(S)