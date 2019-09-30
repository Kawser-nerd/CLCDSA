import numpy as np


def solve(l, r):
    l.reverse()

    stops = []

    if l and r:
        while l and r:
            lx, lp = l.pop()
            rx, rp = r.pop()
            if lp >= rp:
                l.append((lx, lp + rp))
                stops.append(rx)
            else:
                r.append((rx, lp + rp))
                stops.append(lx)

    if l:
        stops.append(l[-1][0])
    else:
        stops.append(r[-1][0])
    stops.append(s)

    return abs(np.diff(np.array(stops, dtype=np.int64))).sum()


n, s = map(int, input().split())
l, r = [], []
for _ in range(n):
    x, p = map(int, input().split())
    if x < s:
        l.append((x, p))
    else:
        r.append((x, p))

print(solve(l, r))