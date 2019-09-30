import sys
from math import atan2, pi
from bisect import bisect_left
N = int(input())
points = [tuple(map(int, l.split())) for l in sys.stdin]
base_x, base_y = points[0]
points.sort(key=lambda p: atan2(p[1]-base_y, p[0]-base_x))
rad_90m, rad_90p, rad_360 = pi / 2 - 1e-9, pi / 2 + 1e-9, pi * 2
ans2, ans3 = 0, 0

for i, (x1, y1) in enumerate(points):
    others = [atan2(y-y1, x-x1) for x, y in (points[:i] + points[i+1:])]
    others.sort()
    first = others[0]
    start = bisect_left(others, first+rad_90m)
    end = bisect_left(others, first+pi)
    others += [rad + rad_360 for rad in others[:bisect_left(others, first+pi)]] + [100]

    for j, rad1 in zip(range(N-1), others):
        while others[start] < rad1 + rad_90m:
            start += 1
        while others[start] <= rad1 + rad_90p:
            start += 1
            ans2 += 1
        while others[end] < rad1 + pi:
            end += 1
        ans3 += end - start

print(N*(N-1)*(N-2)//6-ans2-ans3, ans2, ans3)