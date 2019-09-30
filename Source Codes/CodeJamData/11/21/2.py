#!/usr/bin/env python

import sys


def foo(ifile):
    n = int(ifile.readline())
    a = [ifile.readline().strip() for i in range(n)]
    b = [[0.0]*n for i in range(n)]
    for i in range(n):
        t1 = 0.0
        t2 = 0.0
        for x in a[i]:
            if x == '0':
                t2 += 1
            elif x == '1':
                t1 += 1
                t2 += 1
        for j in range(n):
            if a[i][j] == '0':
                b[i][j] = t1 / (t2-1)
            elif a[i][j] == '1':
                b[i][j] = (t1-1)/(t2-1)
            else:
                b[i][j] = t1 / t2
    WP = [b[i][i] for i in range(n)]

    OWP = [0] * n
    for i in range(n):
        t1 = 0
        t2 = 0
        for j in range(n):
            x = a[i][j]
            if x == '0' or x == '1':
                t1 += b[j][i]
                t2 += 1
        OWP[i] = t1 / t2

    OOWP = [0]*n
    for i in range(n):
        t1 = 0
        t2 = 0
        for j in range(n):
            x = a[i][j]
            if x == '0' or x == '1':
                t1 += OWP[j]
                t2 += 1
        if t1 == 0:
            OOWP[i] = 0.0
        else:
            OOWP[i] = t1 / t2

    res = [WP[i] * 0.25 + OWP[i] * 0.5 + OOWP[i] * 0.25 for i in range(n)]
    return '\n' + '\n'.join([str(x) for x in res])

    #print WP
    #print OWP
    #print OOWP
    #print res


def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

