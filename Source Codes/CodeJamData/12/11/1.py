#!/usr/bin/env python3

import sys

t_n = int(sys.stdin.readline())

for t_t in range(1, t_n+1):
    a, b = list(map(int, sys.stdin.readline().split()))
    p = list(map(float, sys.stdin.readline().split()))
    ans = 1.0 * b + 1
    r = 1.0
    for x in range(0, a + 1):
       ans = min(ans, (a + b - 2 * x) + (1.0 - r) * (b + 1))
       if x < a:
           r *= p[x]
    print("Case #%d: %.10f" % (t_t, ans + 1.0))

