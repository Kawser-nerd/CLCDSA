#!/usr/bin/env python

from __future__ import division

import collections
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

def solve(X, S, R, t, data):
    l = sum(e-b for (b, e, w) in data)
    d = collections.defaultdict(int)
    d[0] = X - l
    for b, e, w in data:
        d[w] = d[w] + e - b
    res = 0
    for sp, le in sorted(d.iteritems()):
        tt = le / (sp + R)
        ut = min(t, tt)
        t -= ut
        res += ut
        le -= ut * (sp + R)
        res += le / (sp + S)
    return res

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        X, S, R, t, N = gcj.tokens(5, int)
        data = []
        for _ in xrange(N):
            data.append(gcj.tokens(3, int))
        print gcj.case(), solve(X, S, R, t, data)

go()
