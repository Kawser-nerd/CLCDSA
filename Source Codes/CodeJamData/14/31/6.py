#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys

from fractions import gcd

def debug(*args):
    print(*args, file=sys.stderr)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    p, q = map(int, fin.readline().split('/'))
    g = gcd(p, q)
    p //= g
    q //= g

    result = None
    if p > q:
        result = "impossible"
    else:
        is_power = None
        for i in range(0, 41):
            power = 2**i
            if q == power:
                is_power = power
        if is_power is None:
            result = "impossible"
        else:
            result = "broken"
            for i in range(1, 41):
                qq = 2**i
                if p * qq >= q:
                    result = str(i)
                    break



    print("Case #%d: %s" % (case, result))