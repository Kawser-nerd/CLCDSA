#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def do_split(f, t):
    return (f + t - 1) / t - 1

def solve(V):
    V.sort(reverse = True)
    best = V[0]
    for j in xrange(1, V[0] + 1):
        r = 0
        for v in V:
            if v <= j:
                break
            r += do_split(v, j)
        best = min(best, r + j)
    return best


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N = int(sys.stdin.readline())
        V = map(int, sys.stdin.readline().split())
        assert(len(V) == N)
        print "Case #%d: %d" % (t, solve(V))

if __name__ == '__main__':
    main()
