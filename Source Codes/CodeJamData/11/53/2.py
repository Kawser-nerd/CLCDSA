#!/usr/bin/env python

import sys

AA = {}

def foo3(a, b, R, C):
    c = [[0] * C for i in range(R)]
    for i in range(R):
        for j in range(C):
            x, y = AA[(i, j, b[i][j])]
            if c[x][y]:
                return 0
            c[x][y] = 1
    return 1

def foo2(a, n, R, C):
    b = [[0] * C for i in range(R)]
    t = 0
    while n > 0:
        b[t//C][t%C] = n % 2
        n //= 2
        t += 1
    return foo3(a, b, R, C)

def fix(i, j, R, C):
    if i == -1:
        i = R-1
    if i == R:
        i = 0
    if j == -1:
        j = C-1
    if j == C:
        j = 0
    return (i, j)
        

def init_AA(a, R, C):
    AA.clear()
    for i in range(R):
        for j in range(C):
            t = a[i][j]
            if t == '|':
                AA[(i, j, 0)] = fix(i-1, j, R, C)
                AA[(i, j, 1)] = fix(i+1, j, R, C)
            elif t == '-':
                AA[(i, j, 0)] = fix(i, j-1, R, C)
                AA[(i, j, 1)] = fix(i, j+1, R, C)
            elif t == '\\':
                AA[(i, j, 0)] = fix(i-1, j-1, R, C)
                AA[(i, j, 1)] = fix(i+1, j+1, R, C)
            elif t == '/':
                AA[(i, j, 0)] = fix(i-1, j+1, R, C)
                AA[(i, j, 1)] = fix(i+1, j-1, R, C)
            else:
                print t
                raise 



def foo(ifile):
    R, C = [int(x) for x in ifile.readline().split()]
    a = [ifile.readline().strip() for i in range(R)]
    init_AA(a, R, C)
    n = 2 ** (R*C)
    res =  0
    for i in range(n):
        res += foo2(a, i, R, C)
    return res


def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

