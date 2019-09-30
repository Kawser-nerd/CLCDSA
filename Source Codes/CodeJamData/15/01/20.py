#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: ovation.py
# $Date: Sat Apr 11 20:10:20 2015 +0800
# $Author: Xiaoyu Liu <i[at]vuryleo[dot]com>

import sys

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        n, l = sys.stdin.readline().split(' ')
        l = [int(i) for i in l if i >= '0' and i <= '9']
        total = 0
        ans = 0
        for i, p in enumerate(l):
            if total < i:
                ans = ans + i - total
                total = i
            total = total + p
        sys.stdout.write("{}\n".format(ans))


# vim: foldmethod=marker
