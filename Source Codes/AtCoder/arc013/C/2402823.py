# -*- coding: utf-8 -*-
def inpl(): return map(int, input().split())


N = int(input())
nim = 0

for _ in range(N):
    X, Y, Z = inpl()
    xmin, ymin, zmin = 10**9+1, 10**9+1, 10**9+1
    xmax, ymax, zmax = 0, 0, 0
    M = int(input())
    for _ in range(M):
        x, y, z = inpl()
        xmin, ymin, zmin = min(xmin, x), min(ymin, y), min(zmin, z)
        xmax, ymax, zmax = max(xmax, x), max(ymax, y), max(zmax, z)

    nim = nim ^ xmin ^ ymin ^ zmin ^ (X-xmax-1) ^ (Y-ymax-1) ^ (Z-zmax-1)

print("WIN" if nim else "LOSE")