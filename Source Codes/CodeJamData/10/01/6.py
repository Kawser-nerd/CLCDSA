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
        n, k = gcj.splitline(int)
        mask = 2**n - 1
        state = 'ON' if (k & mask) == mask else 'OFF'
        print gcj.case(), state
    pass

go()
