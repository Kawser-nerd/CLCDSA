#!/usr/bin/env python

import sys

def foo3(x, aa):
    x = float(x)
    n = len(aa)
    for i in range(n):
        a = aa[i]
        if a[0] >= x:
            if i == 0:
                return a[1]
            return a[1] + (aa[i][1]-aa[i-1][1]+0.0)/(aa[i][0]-aa[i-1][0])*(x - aa[i][0])


def foo2(x, aa, bb):
    return [x, -foo3(x, aa)+foo3(x, bb)]

def foo4(dd):
    n = len(dd)
    res = 0.0
    for i in range(n-1):
        t1 = dd[i]
        t2 = dd[i+1]
        res += (t2[0] - t1[0]) * (t2[1]+t1[1]) / 2.0
    return res

def bar(dd, area):
    cur = 0.0
    n = len(dd)
    for i in range(n-1):
        t1 = dd[i]
        t2 = dd[i+1]
        a1 = (t2[0] - t1[0]) * (t2[1]+t1[1]) / 2.0
        if cur + a1 <= area:
            cur += a1
            continue
        left = area - cur;
        d1 = dd[i][1]
        delta = (t2[1]-t1[1])/(t2[0]-t1[0])
        if delta == 0:
            x = left / d1
        else:
            DD = (d1*d1 + left * delta * 2) ** 0.5
            x = (DD - d1)/delta
        res = [[t1[0]+x, t1[1]+x*delta]] + dd[i+1:]
        dd[:] = res
        return x + t1[0]


def foo(ifile):
    W, L, U, G = [int(x) for x in ifile.readline().split()]
    aa = [[int(x) for x in ifile.readline().split()] for i in range(L)]
    bb = [[int(x) for x in ifile.readline().split()] for i in range(U)]
    cc = set([x[0] for  x in aa]).union(set([x[0] for x in bb]))
    cc = sorted(list(cc))
    dd = []
    for x in cc:
        dd.append(foo2(x, aa, bb))

    total = foo4(dd)
    area = total / G
    res = []
    for i in range(G-1):
        res.append(bar(dd, area))
    return ''.join([("\n%.6f" % x) for x in res])

def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s:%s\n" % (i+1, foo(ifile)))
        ofile.flush()

main(sys.stdin, sys.stdout)

