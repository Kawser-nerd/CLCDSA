#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: pancakes.py
# $Date: Sat Apr 11 20:34:20 2015 +0800
# $Author: Xiaoyu Liu <i[at]vuryleo[dot]com>

import sys, math

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        n = int(sys.stdin.readline())
        l = map(int, sys.stdin.readline().split(' '))
        m = max(l)
        ans = m
        for i in range(1, m + 1):
            d = 0
            for p in l:
                if p > i:
                    d = d + int(math.ceil(p / float(i))) - 1
            ans = min(ans, d + i)
        sys.stdout.write("{}\n".format(ans))


# vim: foldmethod=marker
