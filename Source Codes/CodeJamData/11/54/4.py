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

def isqrt(n):
    xn = 1
    xn1 = (xn + n//xn) // 2
    while abs(xn1 - xn) > 1:
        xn = xn1
        xn1 = (xn + n//xn) // 2
    while xn1**2 > n:
        xn1 -= 1
    return xn1

def solve(s):
    n = len(s)
    pos = [n-1-i for i in xrange(n) if s[i] == '?']
    x = int(s.replace('?', '0'), 2)
    m = len(pos)
    for S in xrange(2**m):
        mask = sum(2**pos[i] for i in xrange(m) if S & (2**i))
        y = x | mask
        if isqrt(y)**2 == y:
            return y

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        s = gcj.token()
        print gcj.case(), bin(solve(s))[2:]

go()
