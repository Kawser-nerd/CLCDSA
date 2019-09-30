#!/usr/bin/env python3
from math import cos, sin, atan2
A, B = map(int, input().split())
if A > B:
    A, B = B, A

N = int(input())
for i in range(N):
    C, D = map(int, input().split())
    if C > D:
        C, D = D, C

    if A <= C and B <= D:
        print('YES')
    elif A >= C and B >= D:
        print('NO')
    else:
        ok = 0
        ng = atan2(B, A) + 1e-2
        while ng - ok > 1e-9:
            m = (ok + ng) / 2
            h = B * sin(m) + A * cos(m)
            if h < D:
                ok = m
            else:
                ng = m

        w = B * cos(ok) + A * sin(ok)
        print(['NO', 'YES'][w <= C])