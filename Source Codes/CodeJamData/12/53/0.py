#!/usr/bin/env python
from __future__ import division
import sys

def read_ints():
    return [int(x) for x in sys.stdin.readline().split()]

def score(M, S0, C0, S, t, p):
    m = min((M - t * C0) // p, t * (S - S0))
    if m >= 0:
        return t * S0 + m
    else:
        return -1

(T,) = read_ints()
for cas in range(1, T + 1):
    M, F, N = read_ints()
    food = []
    for i in range(N):
        food.append(read_ints())
    food = sorted(food)
    ans = 0
    S = 0
    C = F
    for foo in food:
        p = foo[0]
        s = foo[1] + 1
        if s > S:
            S0 = S
            C0 = C
            S = s
            C += (S - S0) * p

            min_t = M // (p * (S - S0) + C0)
            ans = max(ans, score(M, S0, C0, S, min_t, p))
            ans = max(ans, score(M, S0, C0, S, min_t + 1, p))
            max_t = M // C0
            ans = max(ans, score(M, S0, C0, S, max_t, p))
            # print "Min: %d Max: %d" % (min_t, max_t)

    print "Case #%d: %d" % (cas, ans)
