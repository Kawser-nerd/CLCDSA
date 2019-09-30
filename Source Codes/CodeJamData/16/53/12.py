#!/usr/bin/env python

import math
import sys
ls = sys.stdin.readlines()[1:]

def dist(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]
    z = a[2] - b[2]
    return math.sqrt(x*x + y*y + z*z)

COMP = []
def u(i, j):
    COMP[f(i)] = f(j)

def f(i):
    return i if i == COMP[i] else f(COMP[i])

C = 1
while len(ls) > 0:
    n, s = [int(x) for x in ls[0].split()]
    xs = []
    for i in range(n):
        xs.append([float(x) for x in ls[1 + i].split()])
    ls = ls[1 + n:]

    es = []
    for i in range(len(xs)):
        for j in range(i + 1, len(xs)):
            es.append((dist(xs[i], xs[j]), i, j))
    es.sort()

    COMP = [i for i in range(len(xs))]

    ans = 0
    for e in es:
        if f(e[1]) != f(e[2]):
            u(e[1], e[2])
            if f(0) == f(1):
                ans = e[0]
                break

    print "Case #%d: %s" % (C, ans)
    C += 1
