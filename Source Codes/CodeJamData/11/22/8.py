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

def check(data, d, x):
    cur = data[0][0] - x
    for (p, v) in data:
        # cur .. cur + (v-1)*x
        cur = max(cur, p-x)
        if abs(cur - p) > x:
            return False
        if abs(cur + (v-1)*d - p) > x:
            return False
        cur += v * d
    return True

def solve(data, d):
    if check(data, d, 0):
        return 0
    a = 0
    b = 1
    while not check(data, d, b):
        b *= 2
    assert not check(data, d, a)
    assert check(data, d, b)
    while a + 5 < b:
        x = (a + b) // 2
        if check(data, d, x):
            b = x
        else:
            a = x
    while not check(data, d, a):
        a += 1
    return a

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        c, d = gcj.tokens(2, int)
        data = []
        for i in xrange(c):
            p, v = gcj.tokens(2, int)
            data.append((2*p, v))
        print gcj.case(), format(solve(data, 2*d) / 2, '.1f')

go()
