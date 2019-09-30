#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# $File: dijkstra.py
# $Date: Sat Apr 11 21:20:10 2015 +0800
# $Author: Xiaoyu Liu <i[at]vuryleo[dot]com>

import sys
from enum import Enum

class Number(Enum):
    i = 1
    j = 2
    k = 3
    one = 4

table = {
    Number.one: {
        Number.one: (1, Number.one),
        Number.i: (1, Number.i),
        Number.j: (1, Number.j),
        Number.k: (1, Number.k)
    },
    Number.i: {
        Number.one: (1, Number.i),
        Number.i: (-1, Number.one),
        Number.j: (1, Number.k),
        Number.k: (-1, Number.j)
    },
    Number.j: {
        Number.one: (1, Number.j),
        Number.i: (-1, Number.k),
        Number.j: (-1, Number.one),
        Number.k: (1, Number.i)
    },
    Number.k: {
        Number.one: (1, Number.k),
        Number.i: (1, Number.j),
        Number.j: (-1, Number.i),
        Number.k: (-1, Number.one)
    }
}

def mul(a, b):
    ma, va = a
    mb, vb = b
    mr, vr = table[va][vb]
    return (ma * mb * mr, vr)

def form(c):
    return (1, {
        'i': Number.i,
        'j': Number.j,
        'k': Number.k
    }[c])

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        l, x = map(int, sys.stdin.readline().split(' '))
        s = sys.stdin.readline().strip()
        if x > 16:
            x = x - (x - 16) / 4 * 4
        s = s * x
        targets = [(1, Number.i), (1, Number.j), (1, Number.k)]
        current = (1, Number.one)
        targetN = 0
        for digit in s:
            current = mul(current, form(digit))
            if targetN < len(targets):
                if current == targets[targetN]:
                    targetN = targetN + 1
                    current = (1, Number.one)
        if targetN == len(targets) and current == (1, Number.one):
            ans = 'YES'
        else:
            ans = 'NO'
        sys.stdout.write("{}\n".format(ans))

# vim: foldmethod=marker
