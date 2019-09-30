#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def rl(proc=None):
    if proc is not None:
        return proc(sys.stdin.readline())
    else:
        return sys.stdin.readline().rstrip()

def srl(proc=None):
    if proc is not None:
        return map(proc, rl().split())
    else:
        return rl().split()

def main():
    T = rl(int)
    for t in xrange(1, T+1):
        D, N = srl(int)
        tm = 0.0
        for _ in xrange(N):
            K, S = srl(int)
            tm = max(tm, float(D-K)/S)
        print "Case #%d: %.9f" % (t, D/tm)

if __name__ == '__main__':
    main()
