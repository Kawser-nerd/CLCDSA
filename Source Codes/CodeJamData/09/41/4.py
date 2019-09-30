#!/usr/bin/env python

from __future__ import division

import collections
import itertools
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
    t = gcj.line(int)
    for _ in xrange(t):
        n = gcj.line(int)
        data = []
        for _ in xrange(n):
            data.append([int(x) for x in gcj.line()])
            assert len(data[-1]) == n
        print gcj.case(), solve(data)

def solve(data):
    res = 0
    n = len(data)
    gdzie = [0] * n
    for i in xrange(n):
        row = data[i]
        x = n-1
        while x >= 0 and row[x] == 0:
            x -= 1
        gdzie[i] = x
    for i in xrange(n):
        j = min(j for j in xrange(i, n) if gdzie[j] <= i)
        for k in xrange(j, i, -1):
            gdzie[k], gdzie[k-1] = gdzie[k-1], gdzie[k]
            res += 1
    return res

go()
