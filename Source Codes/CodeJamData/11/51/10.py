#!/usr/bin/env python

from __future__ import division

import collections
import math
import itertools
import sys
import operator
import functools

class gcj:
    IN = sys.stdin
    buf = ''
    cur_case = 0

    @classmethod
    def id(x):
        return x

    @classmethod
    def _read_line(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = ''
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def line(cls, conv=str):
        line = cls._read_line()
        return conv(line.rstrip('\r\n'))

    @classmethod
    def splitline(cls, conv=str):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line().lstrip()
        cls.buf = line

    @classmethod
    def token(cls, conv=str):
        cls.whitespace()
        line = cls._read_line()
        spl = line.split(None, 1)
        res = spl[0]
        assert line.startswith(res)
        cls.buf = line[len(res):]
        return conv(res)

    @classmethod
    def tokens(cls, cnt, conv=str):
        return [cls.token(conv) for _ in xrange(cnt)]

    @classmethod
    def case(cls):
        cls.cur_case += 1
        return 'Case #{}:'.format(cls.cur_case)

def merge(p1, p2):
    i = 0
    j = 0
    for x in sorted(set([p[0] for p in p1]) | set(p[0] for p in p2)):
        if p1[i][0] == p2[j][0]:
            yield (x, p1[i][1] - p2[j][1])
            i += 1
            j += 1
        elif p1[i][0] == x:
            x0, y0 = p2[j-1]
            x1, y1 = p2[j]
            y = y0 + (x-x0) * (y1-y0) / (x1-x0)
            yield x, p1[i][1] - y
            i += 1
        else:
            assert p2[j][0] == x
            x0, y0 = p1[i-1]
            x1, y1 = p1[i]
            y = y0 + (x-x0) * (y1-y0) / (x1-x0)
            yield x, y - p2[j][1]
            j += 1

def calc(P):
    P = list(P)
    n = len(P)
    res = 0
    for i in xrange(1, n):
        a = P[i-1]
        b = P[i]
        dx = b[0] - a[0]
        sy = a[1] + b[1]
        res += dx*sy/2
    return res

def calc2(P, target):
    P = list(P)
    n = len(P)
    res = 0
    for i in xrange(1, n):
        a = P[i-1]
        b = P[i]
        dx = b[0] - a[0]
        sy = a[1] + b[1]
        dres = dx*sy/2
        if res + dres >= target:
            T = target - res
            (x0, y0) = a
            (x1, y1) = b
            if abs(y1-y0) < 1e-7:
                return x0 + T / y0
            A = (y1-y0)/(x1-x0)
            B = 2*y0
            C = -2*T
            delta = B**2 - 4*A*C
            sd = math.sqrt(delta)
            s1 = (-B - sd) / (2*A)
            s2 = (-B + sd) / (2*A)
            s = min(s for s in [s1, s2] if s >= 0)
            return x0 + s
        res += dres
    return P[-1][0]

def solve(pl, pu, g):
    total = calc(pu) - calc(pl)
    P = list(merge(pu, pl))
    total = calc(P)
    part = total / g
    for i in xrange(1, g):
        yield calc2(P, i*part)

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        w, l, u, g = gcj.tokens(4, int)
        pl = [gcj.tokens(2, int) for _ in xrange(l)]
        pu = [gcj.tokens(2, int) for _ in xrange(u)]
        assert pl[0][0] == pu[0][0] == 0
        assert pl[-1][0] == pu[-1][0] == w
        res = solve(pl, pu, g)
        print gcj.case()
        for r in res:
            print r

go()
