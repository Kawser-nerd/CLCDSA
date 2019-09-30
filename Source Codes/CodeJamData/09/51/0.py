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
        r, c = gcj.splitline(int)
        data = []
        for _ in xrange(r):
            data.append(gcj.line())
        print gcj.case(), solve(data)
        sys.stdout.flush()

def neigh(cur, data):
    pos, safe = cur
    n = len(pos)
    r = len(data)
    c = len(data[0])
    for i in xrange(n):
        for (dx, dy) in ((-1, 0), (1, 0), (0, 1), (0, -1)):
            a1 = pos[i][0] + dx
            b1 = pos[i][1] + dy
            a2 = pos[i][0] - dx
            b2 = pos[i][1] - dy
            if 0 <= a1 < r and 0 <= b1 < c and data[a1][b1] != '#' and (a1, b1) not in pos:
                if 0 <= a2 < r and 0 <= b2 < c and data[a2][b2] != '#' and (a2, b2) not in pos:
                    pos1 = pos[:i] + ((a1, b1),) + pos[i+1:]
                    safe1 = is_safe(pos1)
                    if safe or safe1:
                        yield (tuple(sorted(pos1)), safe1)

def is_safe(pos):
    vis = set()
    def dfs(x):
        vis.add(x)
        for y in pos:
            if y in vis:
                continue
            if abs(x[0] - y[0]) + abs(x[1] - y[1]) == 1:
                dfs(y)
    dfs(pos[0])
    return len(vis) == len(pos)

def solve(data):
    r = len(data)
    c = len(data[0])
    src = []
    dst = []
    for i in xrange(r):
        for j in xrange(c):
            if data[i][j] in 'ow':
                src.append((i, j))
            if data[i][j] in 'xw':
                dst.append((i, j))
    assert len(src) == len(dst)
    assert is_safe(src)
    assert is_safe(dst)
    src = (tuple(sorted(src)), True)
    dst = (tuple(sorted(dst)), True)
    now = []
    next = [src]
    dest = 0
    vis = set(next)
    while next:
        now = next
        next = []
        for cur in now:
            if cur == dst:
                return dest
            for new in neigh(cur, data):
                if new in vis:
                    continue
                vis.add(new)
                next.append(new)
        dest += 1
    return -1

go()
