#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os


def solve(X, R, C):
    if (R * C) % X:
        return "RICHARD"
    r = min(R, C)
    c = max(R, C)
    if X < 3:
        return "GABRIEL"
    if X > 6:
        return "RICHARD"
    if (X + 1) / 2 > r:
        return "RICHARD"
    if c < X:
        return "RICHARD"
    if X == 3:
        return "GABRIEL"
    if X == 4:
        if r > 2:
            return "GABRIEL"
        else:
            return "RICHARD"
    if X == 5:
        # r >= 3, c >= 5
        if r > 3 or c > 5:
            return "GABRIEL"
        else:
            return "RICHARD"
    if X == 6:
        # r >= 3, c >= 6
        if r > 3:
            return "GABRIEL"
        else:
            return "RICHARD"



def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        X, R, C = map(int, sys.stdin.readline().split())
        print "Case #%d: %s" % (t, solve(X, R, C))

if __name__ == '__main__':
    main()
