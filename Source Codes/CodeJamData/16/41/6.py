#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

B = "PRS"

T = [[0, 1], [1, 2], [2, 0]]

def build(v, n):
    if n == 0:
        return [v]
    n -= 1
    ret = [build(T[v][0], n), build(T[v][1], n)]
    ret.sort()
    return ret[0] + ret[1]

def solve(N, R, P, S):
    ret = []
    for t in "RPS":
        r = build(B.index(t), N)
        r = "".join(B[x] for x in r)
        if r.count("P") == P and r.count("R") == R and r.count("S") == S:
            ret.append(r)
    ret.sort()
    if ret:
        return ret[0]
    else:
        return "IMPOSSIBLE"


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N, R, P, S = map(int, sys.stdin.readline().split())
        print "Case #%s: %s" % (t, solve(N, R, P, S))

if __name__ == '__main__':
    main()
