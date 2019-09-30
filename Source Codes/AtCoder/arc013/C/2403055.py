# -*- coding: utf-8 -*-
from functools import reduce
from operator import xor
def inpl(): return map(int, input().split())
 
 
N = int(input())
cancuts = [0]
 
for _ in range(N):
    X, Y, Z = inpl()
    xmin, ymin, zmin = 10**9+1, 10**9+1, 10**9+1
    xmax, ymax, zmax = 0, 0, 0
    M = int(input())
    for _ in range(M):
        x, y, z = inpl()
        xmin, ymin, zmin = min(xmin, x), min(ymin, y), min(zmin, z)
        xmax, ymax, zmax = max(xmax, x), max(ymax, y), max(zmax, z)
 
    for wmin in [xmin, ymin, zmin]:
        if wmin > 0:
            cancuts.append(wmin)
    for wmax, W in zip([xmax, ymax, zmax], [X, Y, Z]):
        if wmax < W-1:
            cancuts.append(W - wmax - 1)
 
print("WIN" if reduce(xor, cancuts) else "LOSE")