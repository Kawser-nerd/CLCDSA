xa, ya, xb, yb, xc, yc = list(input().split())
a = int(xb) - int(xa)
b = int(yb) - int(ya)
c = int(xc) - int(xa)
d = int(yc) - int(ya)
s = abs(a*d - c*b)/2
print(s)