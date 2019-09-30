#!/usr/bin/python

from __future__ import division

import sys

INF = 2**20

def calc(v0, t, v1):
    if t == 'AND':
        return v0 and v1
    return v0 or v1

def solve(n, v):
    if n > ls:
        return 0 if str(v) == types[n] else INF
    if (n, v) in solve.mem:
        return solve.mem[(n, v)]
    res = INF
    for v0 in True, False:
        for v1 in True, False:
            for t in 'AND', 'OR':
                if v != calc(v0, t, v1):
                    continue
                if changeable[n] and t != types[n]:
                    o = 1
                elif t == types[n]:
                    o = 0
                else:
                    continue
                res = min(res, solve(2*n, v0) + solve(2*n+1, v1) + o)
    solve.mem[(n, v)] = res
    return res

cases = int(sys.stdin.readline())
for case in xrange(1, cases+1):
    m, v = [int(x) for x in sys.stdin.readline().split()]
    ls = (m-1) // 2
    types = [''] * (m+1)
    changeable = [True] * (m+1)
    for i in xrange(1, ls+1):
        nt, nc = [int(x) for x in sys.stdin.readline().split()]
        types[i] = 'AND' if nt == 1 else 'OR'
        changeable[i] = bool(nc)
    for i in xrange(ls+1, m+1):
        nv = int(sys.stdin.readline())
        types[i] = str(bool(nv))

    solve.mem = {}
    res = solve(1, bool(v))

    print "Case #%d:" % case,
    if res == INF:
        print "IMPOSSIBLE"
    else:
        print res
