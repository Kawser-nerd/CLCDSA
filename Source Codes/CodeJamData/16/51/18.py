#!/usr/bin/env python

import sys
ls = sys.stdin.readlines()[1:]

L = ""
cache = {}

def f(a, b):
    if a + 1 == b:
        return 0
    if (a, b) in cache:
        return cache[(a, b)]
    ans = 0
    for i in range(a + 1, b, 2):
        x = 10 if L[a] == L[i] else 5
        ans = max(ans, x + f(a + 1, i) + f(i + 1, b))
    cache[(a, b)] = ans
    return ans

C = 1
for line in ls:
    L = line
    cache.clear()
    print "Case #%d: %s" % (C, f(0, len(line)))
    C += 1
