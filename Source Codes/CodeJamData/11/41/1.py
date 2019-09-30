#!/usr/bin/env python

import sys


def foo(ifile):
    X, S, R, t, N = [int(x) for x in ifile.readline().split()]
    aa = []
    bb = {}
    for i in range(N):
        aa.append([int(x) for x in ifile.readline().split()])
    for i in range(N):
        a = aa[i]
        if a[2] not in bb:
            bb[a[2]] = 0
        bb[a[2]] += a[1] - a[0]
    t2 = X - sum(bb.values())
    bb[0] = t2

    res = 0.0
    bb = sorted(bb.items())
    
    for k, v in bb:
        v = float(v)
        if (R+k)*t > v:
            res += v / (R+k)
            t -= v / (R+k)
        else:
            t2 = (v - (R+k)*t)/(S+k)
            res += t + t2
            t = 0
    return res


def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

