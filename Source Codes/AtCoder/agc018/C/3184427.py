import sys
from heapq import heappush, heappushpop
X, Y, Z = map(int, input().split())
xyz = sorted([list(map(int,l.split()))for l in sys.stdin],key=lambda x:x[0]-x[1])

uq = []
cy = 0
for x, y, z in xyz[:Y]:
    heappush(uq, y - z)
    cy += y
Ly = [cy]
for x, y, z in xyz[Y:Y+Z]:
    cy += y - heappushpop(uq, y - z)
    Ly += [cy]

lq = []
cx = 0
for x, y, z in xyz[-X:]:
    heappush(lq, x - z)
    cx += x
Lx = [cx]
for x, y, z in xyz[Y+Z-1:Y-1:-1]:
    cx += x - heappushpop(lq, x - z)
    Lx += [cx]

print(max(map(sum, zip(Lx, Ly[::-1]))))