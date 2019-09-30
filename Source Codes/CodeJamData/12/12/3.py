# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import sys
import operator

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
        n = gcj.token(int)
        data = []
        for _ in xrange(n):
            a, b = gcj.tokens(2, int)
            data.append((a, b))
        print gcj.case(), solve(data)

def solve(data):
    n = len(data)
    done = [0] * n
    target = 2*n
    moves = 0
    stars = 0
    data.sort(key=operator.itemgetter(1))
    while stars < target:
        ok = False
        for i in xrange(n):
            if done[i] < 2 and data[i][1] <= stars:
                moves += 1
                stars += 2 - done[i]
                done[i] = 2
                ok = True
        if ok:
            continue
        for i in xrange(n-1, -1, -1):
            if done[i] == 0 and data[i][0] <= stars:
                moves += 1
                stars += 1
                done[i] = 1
                break
        else:
            return 'Too Bad'
    return moves

main()
