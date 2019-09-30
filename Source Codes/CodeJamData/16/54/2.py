#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys


def debug(*args):
    print(*args, file=sys.stderr)


def invert(char):
    if char == '1':
        return '0'
    elif char == '0':
        return '1'
    else:
        raise Exception(char)

fin = sys.stdin
T = int(fin.readline())
for case in range(1, T + 1):
    N, L = map(int, fin.readline().split())
    G = fin.readline().split()
    B = fin.readline().strip()

    if B in G:
        result = 'IMPOSSIBLE'
    elif L == 1:
        if B == '0':
            result = '1 1?'
        else:
            result = '0 0?'
    else:
        a = ''
        b = ''
        for c in B:
            b += invert(c) + '?'

            if c == '1':
                a += '01'
            else:
                a += '10'
        a = a[:-2]

        if len(a) + len(b) > 4*L:
            raise Exception("Too large")
        result = a + ' ' + b

    print("Case #%d: %s" % (case, result))

