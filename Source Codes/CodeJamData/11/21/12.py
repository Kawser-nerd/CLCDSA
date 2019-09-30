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

def solve(data):
    n = len(data)
    win = [0]*n
    total = [0]*n
    owp = [0]*n
    oowp = [0]*n
    for i in xrange(n):
        for j in xrange(n):
            if data[i][j] == '.':
                continue
            total[i] += 1
            if data[i][j] == '1':
                win[i] += 1
            assert data[i][j] in '01.'
    for i in xrange(n):
        for j in xrange(n):
            if data[i][j] == '.':
                continue
            w, t = win[j], total[j]-1
            if data[i][j] == '0':
                w -= 1
            owp[i] += w/t
        owp[i] /= total[i]

    for i in xrange(n):
        for j in xrange(n):
            if data[i][j] == '.':
                continue
            oowp[i] += owp[j]
        oowp[i] /= total[i]

    return [.25*win[i]/total[i] + .5*owp[i] + .25*oowp[i] for i in xrange(n)]

def go():
    t = gcj.token(int)
    for _ in xrange(t):
        n = gcj.token(int)
        data = gcj.tokens(n)
        print gcj.case()
        for res in solve(data):
            print repr(res)
go()
