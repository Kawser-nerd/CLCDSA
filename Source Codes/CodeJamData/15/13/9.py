#!/usr/bin/env python3

from math import atan2

def right(p, q):
    return p[0]*q[1]-p[1]*q[0] <= 0

T = int(input())
for case in range(1, T+1):
    N = int(input())
    P = [tuple(map(int, input().split())) for _ in range(N)]
    n = N-1
    print("Case #{}:".format(case))
    for cx, cy in P:
        D = [(x-cx, y-cy) for x, y in P if x != cx or y != cy]
        D.sort(key=lambda p: atan2(*p))
        j = 0
        m = 0
        for i in range(n):
            while right(D[i], D[j%n]) and j < i+n:
                j += 1
            m = max(m, j-i)
        print(n-m)

