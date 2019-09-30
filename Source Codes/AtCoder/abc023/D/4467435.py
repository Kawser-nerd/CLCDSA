import numpy as np
import sys

N = int(input())
hs = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
husen = np.array(hs)
h = husen[:, 0]
s = husen[:, 1]
pmin = np.min(h)
pmax = np.max(h) + N * np.max(s)
point = (pmin + pmax) // 2
j = np.arange(N)

# point?????????
while True:
    t = (point - h) // s
    u = np.sort(t) - j >= 0
    if np.all(u):
        pmax = point
        point = (pmin + point) // 2
        if pmin == pmax:
            break
    else:
        pmin = point + 1
        point = (pmax + point) // 2 + 1
        if pmin == pmax:
            break

print(point)