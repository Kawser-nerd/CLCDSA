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

def check(R, C, data, K):
    for x in xrange(R-K+1):
        for y in xrange(C-K+1):
            sx = 0
            sy = 0
            for x2 in xrange(x, x+K):
                for y2 in xrange(y, y+K):
                    if x2 in (x, x+K-1) and y2 in (y, y+K-1):
                        continue
                    sx += data[x2][y2] * (2*x2 - (2*x + K - 1))
                    sy += data[x2][y2] * (2*y2 - (2*y + K - 1))
            if sx == 0 and sy == 0:
                return True
    return False

def solve(R, C, data):
    M = min(R, C)
    for K in xrange(M, 2, -1):
        if check(R, C, data, K):
            return K
    return 'IMPOSSIBLE'

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        R, C, D = gcj.tokens(3, int)
        data = gcj.tokens(R, lambda s: [int(c) for c in s])
        print gcj.case(), solve(R, C, data)

go()
