#!/usr/bin/env python3

from math import ceil
from fractions import Fraction
from heapq import heapify, heappop, heappushpop

T = int(input())
for case in range(1, T+1):
    B, N = [int(i) for i in input().split()]
    m = [int(i) for i in input().split()]
    tmin = max(N-B, 0) / sum(Fraction(1, i) for i in m)
    N -= sum(ceil(tmin/m[b]) for b in range(B))
    h = [(ceil(tmin/m[b])*m[b], b) for b in range(B)]
    heapify(h)
    t, b = heappop(h)
    for i in range(N-1):
        t, b = heappushpop(h, (t+m[b], b))
    print("Case #{}: {}".format(case, b+1))

