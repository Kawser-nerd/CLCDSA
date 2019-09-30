# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import sys
import fractions

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
    t = gcj.line(int)
    for _ in range(t):
        h, w, d = gcj.splitline(int)
        data = [gcj.line() for _ in range(h)]
        print gcj.case(), solve(d, data)

def solve(d, data):
    h = len(data)
    w = len(data[0])
    cnt = sum(sum(1 for x in row if x == '#') for row in data)
    if cnt > 2*w + 2*h - 4:
        return 'TOO BIG ({})'.format(cnt)
    assert data[0] == data[-1] == w*'#'
    for i in xrange(1, h-1):
        assert data[i].replace('X', '.') == '#' + (w-2)*'.' + '#'
    x, y = next((x, y) for (x, row) in enumerate(data) for (y, c) in
            enumerate(row) if c == 'X')

    w = 2*(w-2)
    h = 2*(h-2)

    x = 2*(x-1) + 1
    y = 2*(y-1) + 1

    d *= 2

    ok = set()

    for dx in range(-d, d+1):
        for dy in range(-d, d+1):
            if dx == dy == 0:
                continue
            if dx**2 + dy**2 > d**2:
                continue
            tx = (x + dx) % (2*h)
            ty = (y + dy) % (2*w)
            if tx in (x, 2*h-x) and ty in (y, 2*w-y):
                g = fractions.gcd(abs(dx), abs(dy))
                ok.add((dx // g, dy // g))
    return len(ok)

main()
