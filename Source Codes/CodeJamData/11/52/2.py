#!/usr/bin/env python

import sys


def foo(ifile):
    a = [int(x) for x in ifile.readline().split()][1:]
    a.sort()
    if len(a) == 0:
        return 0
    bb = {}
    for item in a:
        t = 0
        if item-1 in bb:
            t = bb[item-1][0]
            bb[item-1] = bb[item-1][1:]
            if len(bb[item-1]) == 0:
                del bb[item-1]
        if item not in bb:
            bb[item] = []
        bb[item].append(t+1)
        bb[item].sort()
    res = len(a)
    for k, v in bb.items():
        res = min(res, min(v))
    return res




def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

