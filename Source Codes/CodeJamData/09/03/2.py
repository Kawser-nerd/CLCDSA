#!/usr/bin/env python

from __future__ import division

import sys
import itertools

PATTERN = 'welcome to code jam'
MOD = 10**4

def solve(text):
    k = len(PATTERN)
    n = len(text)
    counts = [[0] * (n+1) for _ in xrange(k + 1)]
    for j in reversed(xrange(n + 1)):
        counts[k][j] = 1
    for i in reversed(xrange(k)):
        for j in reversed(xrange(n)):
            counts[i][j] = counts[i][j+1]
            if PATTERN[i] == text[j]:
                counts[i][j] += counts[i+1][j+1]
            counts[i][j] %= MOD
    return counts[0][0] % MOD

def go():
    n = int(sys.stdin.readline())
    for i in xrange(n):
        text = sys.stdin.readline().strip()
        print 'Case #%d: %.4d' % (i+1, solve(text))

go()
