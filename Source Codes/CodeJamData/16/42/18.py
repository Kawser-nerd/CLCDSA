#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys
from itertools import combinations


def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N, K = list(map(int, fin.readline().split()))
    P = list(map(float, fin.readline().split()))
    P.sort()
    M = K // 2 + 1

    best = (0, [])

    for c in range(K+1):
        combination = P[:c]
        if c < K:
            combination += P[-(K-c):]

        s = [0] * M
        s[0] = 1
        for a1 in combination:
            a0 = 1 - a1
            ss = [0] * M
            ss[0] = s[0] * a0
            for k in range(M):
                ss[k] = s[k-1] * a1 + s[k] * a0
            s = ss
        best = max(best, (s[-1], combination))
    # debug(case, P, best)

    print("Case #%d: %s" % (case, best[0]))

