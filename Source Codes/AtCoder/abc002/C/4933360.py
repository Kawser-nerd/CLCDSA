xa, ya, xb, yb, xc, yc = map(int, input().split())
xb = xb - xa
xc = xc - xa
yb = yb - ya
yc = yc - ya
print(abs(xb*yc-xc*yb)/2)