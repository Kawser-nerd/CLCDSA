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

def main():
    t = gcj.token(int)
    for _ in xrange(t):
        a, b = gcj.tokens(2, int)
        p = gcj.tokens(a, float)
        print gcj.case(), '{:.6f}'.format(solve(p, b))

def solve(p, b):
    a = len(p)
    res = b + 2
    gp = 1
    for i in xrange(a+1):
        cur = a - i + b - i + 1
        cur += (1 - gp) * (b + 1)
        res = min(res, cur)
        if i < a:
            gp *= p[i]
    return res

main()
