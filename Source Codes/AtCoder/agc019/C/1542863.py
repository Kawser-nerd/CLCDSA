from sys import stdin
input = stdin.readline
from decimal import Decimal as D
 
from bisect import bisect_left as bl
def LIS(L):
    best = []
    for i in L:
        pos = bl(best, i)
        if len(best) <= pos: best.append(i)
        else: best[pos] = i
    return len(best)

xflip = 1
yflip = 1
x1, y1, x2, y2 = map(int,input().split())
if x1 > x2:
    xflip = -1
    x1, x2 = x2, x1
if y1 > y2:
    yflip = -1
    y1, y2 = y2, y1
points = []
n = int(input())
for i in range(n):
    x, y = map(int,input().split())
    if x1 <= x <= x2 and y1 <= y <= y2:
        points.append((x*xflip,y*yflip))
points = [y for x,y in sorted(points)]
 
foun = LIS(points)
dist = D(100)*(x2-x1+y2-y1)
dx = D('-4.2920367320510338076867835')*foun
if foun == min(x2-x1+1, y2-y1+1): dx+= D('15.7079632679489661923132165')
print(dist+dx)