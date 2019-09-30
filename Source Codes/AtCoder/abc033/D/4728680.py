from math import atan2, pi
from bisect import bisect_left

n = int(input())
xy = [tuple(int(x) for x in input().split()) for _ in range(n)]

C = 0
D = 0

P = pi / 2 - 1e-9
Q = pi / 2 + 1e-9
Z = pi * 2

hq = []

for i, (x0, y0) in enumerate(xy):
    b = [atan2(y-y0, x-x0) for x, y in (xy[:i] + xy[i+1:])]
    b.sort()
    s = bisect_left(b, b[0] + P)
    t = bisect_left(b, b[0] + pi)
    b += [x + Z for x in b[:t] + [10]]
    for j, r in zip(range(n-1), b):
        while b[s] < r + P:
            s += 1
        while b[s] <= r + Q:
            s += 1
            C += 1
        while b[t] < r + pi:
            t += 1
        D += t - s

print(n*(n-1)*(n-2) // 6 - D - C, C, D)