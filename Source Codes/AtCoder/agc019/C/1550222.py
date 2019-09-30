# -*- coding: utf-8 -*-
from bisect import bisect_left, insort
from math import pi
 
def inpl(): return tuple(map(int, input().split()))
sx, sy, gx, gy = inpl()
 
yrev = False
if sx > gx:
    sx, sy, gx, gy = gx, gy, sx, sy
 
if sy > gy:
    sy, gy = 10**8 - 1 - sy, 10**8 - 1 - gy 
    yrev = True
 
N = int(input())
fountains = []
 
for _ in range(N):
    x, y = inpl()
    if yrev:
        y = 10**8 - 1 - y
    if (sx <= x <= gx) & (sy <= y <= gy):
        fountains.append([x, y])

fountains.sort()
 
L = []
if len(fountains):
    L.append(fountains[0][1])
 
for f in fountains: # ???????
    x, y = f
    if L[-1] < y:
        L.append(y)
    else:
        L[bisect_left(L, y)] = y
 
if min(gx - sx, gy - sy) + 1 == len(L):
    print(((gx - sx)+(gy - sy))*100 - (20 - 5*pi)*(len(L)-1) + (10*pi - 20))
else:
    print(((gx - sx)+(gy - sy))*100 - (20 - 5*pi)*len(L))