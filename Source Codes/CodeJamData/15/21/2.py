#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys

from fractions import gcd

def debug(*args):
    print(*args, file=sys.stderr)

def reverse(nr):
    return int(str(nr)[::-1])

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    n = int(fin.readline())
    count = 0
    while n > 0:
        digits = str(n)
        halfcount = (len(digits)+1)//2
        rev = reverse(n)
        mod = n % (10 ** halfcount)

        if mod == 1 and n != rev:
            n = rev
            count += 1
        elif mod <= 1:
            n -= 1
            count += 1
        else:
            n -= (mod-1)
            count += (mod-1)

    print("Case #%d: %s" % (case, count))