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
    t = gcj.line(int)
    for _ in xrange(t):
        p = gcj.line(int)
        data = gcj.splitline(int)
        assert len(data) == 2**p
        prices = []
        for i in xrange(p):
            prices.append(gcj.splitline(int))
            assert len(prices[-1]) == 2**(p-i-1)
        print gcj.case(), solve(p, data, prices)

def solve(p, data, prices):
    n = len(data)
    cache = {}
    for a in xrange(n):
        for up in xrange(p+1):
            if p-up <= data[a]:
                cache[(a, a, up)] = 0
            else:
                cache[(a, a, up)] = 2**42
    for l in xrange(1, p+1):
        s = 2**l
        c = 2**(p-l)
        assert s*c == n
        for i in xrange(c):
            a = i*s
            b = (i+1)*s - 1
            b2 = a + s//2 - 1
            a2 = b2 + 1
            for up in xrange(p-l+1):
                cache[(a, b, up)] = min(cache[(a, b2, up)] + cache[(a2, b, up)], prices[l-1][i] + cache[(a, b2, up+1)] + cache[(a2, b, up+1)])
    return cache[(0, n-1, 0)]

go()
