#!/usr/bin/env python

import sys


def foo(ifile):
    C, D = [int(x) for x in ifile.readline().split()]
    a = []
    for i in range(C):
        P, V = [int(x) for x in ifile.readline().split()]
        a += [[P, V]]
    n = len(a)
    b = [[a[i][0], a[i][0]] for i in range(n)]
    for i in range(n):
        count = 0
        for j in range(i)[::-1]:
            count += a[j][1]
            b[i][1] = max(b[i][1], a[j][0] + count*D)
        count = 0
        for j in range(i+1, n):
            count += a[j][1]
            b[i][0] = min(b[i][0], a[j][0] + count*D)
    return "%.1f" % (max([b[i][1]-b[i][0]+D*a[i][1]-D for i in range(n)]) / 2.0)



def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

