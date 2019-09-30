import sys
import math
a = input().split(' ')
xa = int(a[0])
ya = int(a[1])
xb = int(a[2])
yb = int(a[3])
T = int(a[4])
V = int(a[5])
n = int(input())

for i in range(0,n):
    pos = input().split(' ')
    x = int(pos[0])
    y = int(pos[1])
    dx1 = x - xa
    dy1 = y - ya
    dx2 = xb - x
    dy2 = yb - y
    d1 = dx1 * dx1 + dy1 * dy1
    d2 = dx2 * dx2 + dy2 * dy2
    if math.sqrt(d1) + math.sqrt(d2) <= T * V:
        print("YES")
        sys.exit()
print("NO")