#!/usr/bin/env python

from __future__ import division

import collections
import itertools
import sys

class gcj:
    IN = sys.stdin
    number = 0

    @classmethod
    def case(cls):
        cls.number += 1
        return 'Case #%d:' % cls.number

    @classmethod
    def line(cls, type=str):
        line = cls.IN.readline()
        return type(line.strip('\n'))

    @classmethod
    def splitline(cls, type=str):
        line = cls.IN.readline()
        return [type(x) for x in line.split()]

def go():
    T = gcj.line(int)
    for _ in xrange(T):
        R, k, N = gcj.splitline(int)
        groups = gcj.splitline(int)
        assert len(groups) == N
        print gcj.case(), solve(R, k, groups)

def solve(R, k, groups):
    n = len(groups)
    memo = [None] * n
    for i in xrange(n):
        x = 0
        m = 0
        while m < n and x + groups[(i+m) % n] <= k:
            x += groups[(i+m) % n]
            m += 1
        memo[i] = ((i+m) % n, x)
    i = 0
    res = 0
    r = 0
    when = [None] * n
    while r < R:
        if when[i] is not None:
            r1, res1 = when[i]
            cnt = (R - r) // (r - r1)
            if cnt > 0:
                r += cnt * (r - r1)
                res += cnt * (res - res1)
                continue
        when[i] = (r, res)
        i, x = memo[i]
        res += x
        r += 1
    return res

go()
