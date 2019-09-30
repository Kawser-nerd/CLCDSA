# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import sys

class gcj:
    IN = sys.stdin
    buf = None

    identity = lambda x: x

    @classmethod
    def _read_line_raw(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = None
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def _read_line_view(cls):
        line = cls._read_line_raw()
        if not isinstance(line, memoryview):
            line = memoryview(line)
        return line

    @classmethod
    def _read_line(cls):
        line = cls._read_line_raw()
        if isinstance(line, memoryview):
            line = line.tobytes()
        return line

    @classmethod
    def line(cls, conv=identity):
        line = cls._read_line()
        return conv(line.rstrip(b'\r\n'))

    @classmethod
    def splitline(cls, conv=identity):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line_raw()
            i = 0
            l = len(line)
            while i < l and line[i].isspace():
                i += 1
            line = memoryview(line)[i:]
        cls.buf = line

    @classmethod
    def token(cls, conv=identity):
        cls.whitespace()
        line = cls._read_line_view()
        i = 0
        l = len(line)
        while i < l and not line[i].isspace():
            i += 1
        cls.buf = line[i:] if i < l else None
        return conv(line[:i].tobytes())

    @classmethod
    def tokens(cls, cnt, conv=identity):
        return [cls.token(conv) for _ in range(cnt)]

    current_case = 0

    @classmethod
    def case(cls):
        cls.current_case += 1
        return b'Case #{}:'.format(cls.current_case)

def solve():
    r, c, m = gcj.tokens(3, int)
    res = solve_(r, c, m)
    if res is None:
        res = transpose(solve_(c, r, m))
    if res is None:
        return 'Impossible'
    return '\n'.join(''.join(s) for s in res)

def transpose(data):
    if data is None:
        return None
    r = len(data)
    c = len(data[0])
    return [[data[i][j] for i in range(r)] for j in range(c)]

def solve_(r, c, m):
    e = r*c-m
    assert e > 0
    if r == 1:
        return ['c' + '.'*(e-1) + '*'*m]
    if c == 1:
        return None
    if e == 1:
        res = [['*'] * c for _ in range(r)]
        res[0][0] = 'c'
        return res
    for a in range(2, r+1):
        for b in range(2, c+1):
            if a*b < e or e < 2*(a+b-2):
                continue
            l = [b]*2 + [2]*(a-2)
            s = sum(l)
            i = 2
            while s < e:
                if l[i] < b:
                    l[i] += 1
                    s += 1
                else:
                    i += 1
            res = [['*'] * c for _ in range(r)]
            for i in range(a):
                for j in range(l[i]):
                    res[i][j] = '.'
            res[0][0] = 'c'
            return res
    return None

def main():
    t = gcj.token(int)
    for _ in xrange(t):
        print gcj.case()
        print solve()

main()
