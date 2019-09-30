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

def solve(board, k):
    n = len(board)
    res = []
    for i in xrange(n):
        s = [x for x in board[i] if x != '.']
        m = len(s)
        board[i] = ((n-m)*'.') + (''.join(s))
    for c in ('R', 'B'):
        ok = False
        for i in xrange(n):
            for j in xrange(n):
                if board[i][j] != c:
                    continue
                for di, dj in [(0, 1), (1, 0), (1, 1), (1, -1)]:
                    if 0 <= i+(k-1)*di < n and 0 <= j+(k-1)*dj < n:
                        for d in xrange(1, k):
                            if board[i+d*di][j+d*dj] != c:
                                break
                        else:
                            ok = True
                            break
        res.append(ok)
    return res

def go():
    t = gcj.line(int)
    for _ in xrange(t):
        n, k = gcj.splitline(int)
        board = [gcj.line() for _ in xrange(n)]
        red, blue = solve(board, k)
        print gcj.case(), 
        if red and blue:
            print 'Both'
        elif red:
            print 'Red'
        elif blue:
            print 'Blue'
        else:
            print 'Neither'

go()
