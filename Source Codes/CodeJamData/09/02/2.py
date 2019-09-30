#!/usr/bin/env python

from __future__ import division

import sys
import itertools

def fill(i, j, mark, map, res):
    h = len(map)
    w = len(map[0])
    history = []
    while res[i][j] == '?':
        history.append((i, j))
        cand = []
        for di, dj in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                if 0 <= i+di < h and 0 <= j+dj < w and map[i+di][j+dj] < map[i][j]:
                    cand.append((map[i+di][j+dj], i+di, j+dj))
        if not cand:
            res[i][j] = mark
            mark = chr(ord(mark) + 1)
        else:
            _, i, j = min(cand)
    for i_, j_ in history:
        res[i_][j_] = res[i][j]
    return mark

def solve(map):
    h = len(map)
    w = len(map[0])
    res = [['?' for j in xrange(w)] for i in xrange(h)]
    basin = 'a'
    for i in xrange(h):
        for j in xrange(w):
            basin = fill(i, j, basin, map, res)
    return res

def go():
    t = int(sys.stdin.readline())
    for i in xrange(t):
        h, w = [int(x) for x in sys.stdin.readline().split()]
        map = []
        for _ in xrange(h):
            line = [int(x) for x in sys.stdin.readline().split()]
            assert len(line) == w
            map.append(line)
        res = solve(map)
        print 'Case #%d:' % (i+1)
        for line in res:
            print ' '.join(line)

go()
