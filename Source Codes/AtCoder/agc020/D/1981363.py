#!/usr/bin/env python3
import math
Q = int(input())
for _ in range(Q):
    A, B, C, D = map(int, input().split())
    K = math.ceil(max(A, B) / (min(A, B) + 1))
    lo, hi = 0, A + 1
    while hi - lo > 1:
        mid = (lo + hi) // 2
        rA, rB = A - mid, B - max(0, (mid - 1) // K)
        if (rA + 1) * K < rB:
            hi = mid
        else:
            lo = mid

    f = ''
    for i in range(C - 1, D):
        na = lo
        nb = max(0, (na - 1) // K)
        if i < nb * (K + 1):
            f += ('A', 'B')[i % (K + 1) == K]
        elif i < na + nb:
            f += 'A'
        else:
            j = A + B - i - 1
            nb = B - nb
            na = max(0, (nb - 1) // K)
            if j < na * (K + 1):
                f += ('B', 'A')[j % (K + 1) == K]
            else:
                f += 'B'
    print(f)