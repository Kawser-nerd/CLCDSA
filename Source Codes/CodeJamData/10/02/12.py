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
    c = gcj.line(int)
    for _ in xrange(c):
        events = gcj.splitline(int)[1:]
        print gcj.case(), solve(events)

def gcd(a, b):
    while a != 0:
        a, b = b%a, a
    return b

def mgcd(l):
    l = iter(l)
    res = l.next()
    for x in l:
        res = gcd(res, x)
        if res == 1:
            break
    return res

def solve(events):
    T = mgcd(x - y for x in events for y in events if x > y)
    return (-min(events)) % T

go()
