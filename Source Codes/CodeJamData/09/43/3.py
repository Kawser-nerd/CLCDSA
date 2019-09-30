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
    T = gcj.line(int)
    for _ in xrange(T):
        n, k = gcj.splitline(int)
        data = []
        for i in xrange(n):
            data.append(gcj.splitline(int))
            assert len(data[-1]) == k
        print gcj.case(), solve(data)

def maxmatching(kraw):
    def dfs(i):
        if vis[i]:
            return False
        vis[i] = True
        if i < n:
            for j in kraw[i]:
                if n+j == mat[i]:
                    continue
                if dfs(n+j):
                    mat[i] = n+j
                    mat[n+j] = i
                    return True
        else:
            if mat[i] is None:
                return True
            else:
                if dfs(mat[i]):
                    mat[i] = None
                    return True
        return False
    n = len(kraw)
    mat = [None] * (2*n)
    res = 0
    while True:
        vis = [False] * (2*n)
        ok = False
        for i in xrange(n):
            if mat[i] is None and dfs(i):
                res += 1
                ok = True
        if not ok:
            break
    return res

def solve(data):
    n = len(data)
    k = len(data[0])
    kraw = [[] for _ in xrange(n)]
    for i in xrange(n):
        for j in xrange(n):
            if all(a < b for (a, b) in zip(data[i], data[j])):
                kraw[i].append(j) # i less than j
    return n - maxmatching(kraw)

go()
