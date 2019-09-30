# encoding: UTF-8

from __future__ import absolute_import, division

from future_builtins import *
range = xrange

import collections
import itertools
import sys
from fractions import Fraction as F

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

Car = collections.namedtuple('Car', 'lane speed pos')

def main():
    t = gcj.token(int)
    for _ in xrange(t):
        n = gcj.token(int)
        data = []
        for _ in xrange(n):
            c = gcj.token()
            s, p = gcj.tokens(2, int)
            data.append(Car(int(c == 'L'), s, p))
        print gcj.case(), solve(data)

def col(pa, pb, sa, sb):
    if pa >= pb:
        return 0
    if sa <= sb:
        return 0
    return F(pb-pa, sa-sb)

def possible(S, data, t):
    n = len(data)
    for i in xrange(n):
        pi = data[i].pos + t*data[i].speed
        li = 1 if S & (1 << i) else 0
        for j in xrange(i+1, n):
            pj = data[j].pos + t*data[j].speed
            lj = 1 if S & (1 << j) else 0
            if li == lj:
                if abs(pi - pj) < 5:
                    return False
                if pi == pj+5 and data[i].speed < data[j].speed:
                    return False
                if pj == pi+5 and data[j].speed < data[i].speed:
                    return False
    return True

def reachable(S, C, data, t):
    n = len(data)
    for i in xrange(n):
        lis = 1 if S & (1 << i) else 0
        lic = 1 if C & (1 << i) else 0
        if lic == lis:
            continue
        pi = data[i].pos + t*data[i].speed
        for j in xrange(n):
            pj = data[j].pos + t*data[j].speed
            if i != j and abs(pi - pj) < 5:
                return False
    return True

def solve(data):
    n = len(data)
    times = set([0])
    for a in data:
        for b in data:
            times.add(col(a.pos+5, b.pos, a.speed, b.speed))
    times = sorted(times)
    S = sum(1 << i for i in xrange(n) if data[i].lane == 1)
    cur = set([S])
    for t in times:
        new = set()
        for S in xrange(2**n):
            if not possible(S, data, t):
                continue
            ok = True
            for C in cur:
                if reachable(S, C, data, t):
                    new.add(S)
                    break
        if not new:
            return '{:.6f}'.format(float(t))
        cur = new
    return 'Possible'

main()
