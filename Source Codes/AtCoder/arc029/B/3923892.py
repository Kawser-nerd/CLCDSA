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
        for _ in range(30):
            m = (ok + ng) / 2
            w = B * cos(m) + A * sin(m)
            h = B * sin(m) + A * cos(m)
            if abs(h - D) < 1e-3:
                break
            if h < D:
                ok = m
            else:
                ng = m

        print(['NO', 'YES'][w <= C])