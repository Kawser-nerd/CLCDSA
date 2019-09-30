#!/usr/bin/env python

from __future__ import division

import sys
import itertools
import collections
from decimal import Decimal, localcontext

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

def Newton(n, k):
    if k < 0 or k > n:
        return 0
    if n == 0:
        return 1
    res = 1
    for i in xrange(n-k+1, n+1):
        res *= i
    for i in xrange(2, k+1):
        res //= i
    return res

def P(i, j, c, n):
    assert i <= j
    if j < n:
        return 0
    t = j - i
    if t > n:
        return 0
    return Decimal(Newton(i, n-t)) * Newton(c-i, t) / Newton(c, n)

def solve(c, n):
    with localcontext() as ctx:
        ctx.prec = 42
        E = [None] * (c+1)
        E[c] = 0
        for i in reversed(xrange(c)):
            s = 1
            for j in xrange(i + 1, c+1):
                s += P(i, j, c, n) * E[j]
            E[i] = s / (1 - P(i, i, c, n))
        return E[0]

def go():
    t = gcj.line(int)
    for _ in xrange(t):
        c, n = gcj.splitline(int)
        print gcj.case(), solve(c, n)

go()
