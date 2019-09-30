#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys
import os

def solve(s):
    have = 0
    ret = 0
    for i, v in enumerate(map(int, s)):
        if have < i:
            ret += 1
            have += 1
        have += v
    return ret


def main():
    T = int(sys.stdin.readline())
    for t in xrange(1, T+1):
        _, s = sys.stdin.readline().split()
        print "Case #%d: %d" % (t, solve(s))


if __name__ == '__main__':
    main()
