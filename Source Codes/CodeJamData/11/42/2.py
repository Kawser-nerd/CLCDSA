#!/usr/bin/env python

import sys

def foo2(x, y, n, a):
    tx = 0
    ty = 0
    tt = 0
    for i in range(x, x+n):
        for j in range(y, y+n):
            tx += a[i][j] * i
            ty += a[i][j] * j
            tt += a[i][j]
    for i, j in [[x, y], [x, y+n-1], [x+n-1, y], [x+n-1, y+n-1]]:
        tx -= a[i][j] * i
        ty -= a[i][j] * j
        tt -= a[i][j]

    N = n*n-4
    N = tt
    cx = x+x+n-1
    cy = y+y+n-1
    print x, y, cx, cy, tx, ty, n, N, tx*2, cx*N, ty*2, cy*N
    return cx*N == tx*2 and cy*N == ty*2

def foo3(x1, y1, n, a, d):
    x = x1-1
    y = y1-1
    x2 = x1+n-1
    y2 = y1+n-1
    t0 = d[x2][y2][0]+d[x][y][0]-d[x2][y][0]-d[x][y2][0]
    t1 = d[x2][y2][1]+d[x][y][1]-d[x2][y][1]-d[x][y2][1]
    t2 = d[x2][y2][2]+d[x][y][2]-d[x2][y][2]-d[x][y2][2]
    for i, j in [[x1, y1], [x2, y2], [x1, y2], [x2, y1]]:
        t0 -= a[i][j]
        t1 -= a[i][j] * i
        t2 -= a[i][j] * j
    cx = x1+x2
    cy = y1+y2
    #print x1, y1, cx, cy, t1, t2, n, t0
    return  cx*t0 == t1*2 and cy*t0 == t2*2


def buildd(a):
    n = len(a)
    m = len(a[0])
    res = [[[0,0,0] for i in range(m+1)] for i in range(n+1)] 
    for i in range(n):
        t0 = 0
        t1 = 0
        t2 = 0
        for j in range(m):
            t0 += a[i][j];
            t1 += a[i][j] * i
            t2 += a[i][j] * j
            if(i == 0):
                res[i][j] = [t0, t1, t2]
            else:
                res[i][j] = [res[i-1][j][0] + t0, res[i-1][j][1] + t1, res[i-1][j][2]+t2]
    return res

def foo(ifile):
    R, C, D = [int(x) for x in ifile.readline().split()]
    a = [[int(x) for x in ifile.readline().strip()] for i in range(R)]
    N = min(R, C)
    d = buildd(a)
    for res in range(N, 2, -1):
        for i in range(R):
            if i+res > R:
                break
            for j in range(C):
                if j + res > C:
                    break
                if foo3(i, j, res, a, d):
                    return res
    return "IMPOSSIBLE"


def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

