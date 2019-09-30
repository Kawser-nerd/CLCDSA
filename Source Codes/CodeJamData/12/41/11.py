# -*- coding: utf-8 -*-
from collections import deque

import sys
fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    N = int(fin.readline())
    vines = []
    for i in range(N):
        di, li = map(int, fin.readline().split())
        vines.append((di, li))

    D = int(fin.readline())

    vines.append((D, 0))

    queue = deque([(vines[0][0], vines[0][0]*2)])

    for d, l in vines[1:]:
        while queue and queue[0][1] < d:
            queue.popleft()
        if not queue:
            break
        distance = min(l, d - queue[0][0])
        p = d + distance
        if p > queue[-1][1]:
            queue.append((d, p))

    success = bool(queue)
    print("Case #%d: %s" % (case, success and "YES" or "NO"))

