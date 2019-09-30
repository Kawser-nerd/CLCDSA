#!/usr/bin/env python

from __future__ import division

import collections
import itertools
import sys
import copy

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
        r = gcj.line(int)
        grid = [[0] * 101 for _ in xrange(101)]
        for _ in xrange(r):
            x1, y1, x2, y2 = gcj.splitline(int)
            for x in xrange(x1, x2+1):
                for y in xrange(y1, y2+1):
                    grid[x][y] = 1
        print gcj.case(), solve(grid)

def solve(grid):
    t = 0
    while True:
        done = True
        for x in xrange(100, 0, -1):
            for y in xrange(100, 0, -1):
                if grid[x][y] == 1:
                    done = False
                if grid[x-1][y] == grid[x][y-1]:
                    grid[x][y] = grid[x][y-1]
        if done:
            return t
        t += 1

go()
