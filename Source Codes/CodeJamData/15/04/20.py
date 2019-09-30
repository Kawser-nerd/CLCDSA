#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: omino.py
# $Date: Sat Apr 11 22:53:56 2015 +0800
# $Author: Xiaoyu Liu <i[at]vuryleo[dot]com>

import sys

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        x, r, c = map(int, sys.stdin.readline().split(' '))
        r, c = min(r, c), max(r, c)
        ans = 'GABRIEL'
        if x == 1:
            pass
        elif x > 6:
            ans = 'RICHARD'
        elif (r * c) % x != 0:
            ans = 'RICHARD'
        elif c < x:
            ans = 'RICHARD'
        elif x > 2 and r == 1:
            ans = 'RICHARD'
        elif x > 4 and r < 3:
            ans = 'RICHARD'
        elif (x, r) == (4, 2):
            ans = 'RICHARD'
        elif (x, r, c) == (5, 3, 5):
            ans = 'RICHARD'
        elif (x, r) == (6, 3):
            ans = 'RICHARD'
        sys.stdout.write("{}\n".format(ans))

# vim: foldmethod=marker
