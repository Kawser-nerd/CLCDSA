#!/usr/bin/env python

from __future__ import division

import sys
import itertools
import collections

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

H = collections.defaultdict(dict)

def happy(i, b):
    vis = set([1])
    ii = i
    while i not in vis:
        if i in H[b]:
            return H[b][i]
        vis.add(i)
        j = 0
        while i > 0:
            j += (i % b) ** 2
            i //= b
        i = j
    H[b][ii] = (i == 1)
    return H[b][ii]

def solve(bases):
    for i in itertools.count(2):
        for b in bases:
            if not happy(i, b):
                break
        else:
            return i

def go():
    t = gcj.line(int)
    for _ in xrange(t):
        bases = gcj.splitline(int)
        print gcj.case(), solve(bases)

go()
