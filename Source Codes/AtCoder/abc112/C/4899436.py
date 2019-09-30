from itertools import *

n = int(input())
xyh = []
for i in range(n):
    xyh += [list(map(int, input().split()))]
xyh.sort(reverse=True, key=lambda x: x[2])
[x0, y0, h0] = xyh[0]
for x, y in product(range(0, 101), range(0, 101)):
    h = h0 + abs(x - x0) + abs(y - y0)
    for k in xyh[1:]:
        if k[2] != max(h - abs(x - k[0]) - abs(y - k[1]), 0):
            break
    else:
        break
print(x, y, h)