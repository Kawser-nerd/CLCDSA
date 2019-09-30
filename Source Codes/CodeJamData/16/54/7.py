#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        N, L = map(int, sys.stdin.readline().split())
        G = sys.stdin.readline().split()
        assert len(G) == N and len(G[0]) == L
        B = sys.stdin.readline().strip()
        assert len(B) == L
        if B in G:
            ret = "IMPOSSIBLE"
        else:
            ret = "0" + "1" * (L-1) + " " + "?0" * L
        print "Case #%d: %s" % (t, ret)


if __name__ == '__main__':
    main()
