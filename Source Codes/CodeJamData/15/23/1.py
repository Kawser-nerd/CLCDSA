#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
import heapq

def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N = int(fin.readline())

    heap = []
    hikers = 0

    for i in range(N):
        d, h, m = map(int, fin.readline().split())
        for p in range(m, m+h):
            t = p * (360-d) / 360.0
            heapq.heappush(heap, (t, 1, p))
            hikers += 1

    current = hikers
    least = current
    while current <= hikers*2:
        token = heapq.heappop(heap)
        t, d, p = token
        current -= d
        least = min(current, least)
        heapq.heappush(heap, (t + p, -1, p))

    result = least
    debug("Case %d" % case)
    print("Case #%d: %s" % (case, result))
