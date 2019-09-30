#!/usr/bin/env python

from __future__ import division

import collections
import itertools
import math
import sys

class gcj:
    IN = sys.stdin
    number = 0

    @classmethod
    def case(cls):
        cls.number += 1
        return 'Case #%d:' % cls.number

    @classmethod
    def line(cls, type=str):
        line = cls.IN.readline()
        return type(line.strip('\n'))

    @classmethod
    def splitline(cls, type=str):
        line = cls.IN.readline()
        return [type(x) for x in line.split()]

def go():
    c = gcj.line(int)
    for _ in xrange(c):
        n = gcj.line(int)
        data = []
        for _ in xrange(n):
            data.append(gcj.splitline(int))
        print gcj.case(), '%.10f' % min(solve(data))

def solve(data):
    n = len(data)
    for i in xrange(n):
        left = set([i])
        right = set(xrange(n)) - left
        r = max(calc(data[i] for i in right), calc(data[i] for i in left))
        yield r

def calc(data):
    data = list(data)
    if len(data) > 2:
        return 31337
    if len(data) == 0:
        return 0
    if len(data) == 1:
        return data[0][2]
    assert len(data) == 2
    x1, y1, r1 = data[0]
    x2, y2, r2 = data[1]
    return (r1 + r2 + math.hypot(x1-x2, y1-y2)) / 2

go()
