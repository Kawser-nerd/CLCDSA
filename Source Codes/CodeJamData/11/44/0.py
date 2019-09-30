#!/usr/bin/env python

import sys

def calc(b, route):
    res = set()
    for x in route[:-1]:
        res =  res.union( b[x])
    return len(res - set(route[:-1]))



def foo(ifile):
    P, W = [int(x) for x in ifile.readline().split()]
    a = [[int(x) for x in y.split(',')] for y in ifile.readline().split()]
    b = [[] for i in range(P)]
    for i, j in a:
        b[i].append(j)
        b[j].append(i)
    c = [None] * P
    c[0] = [0, [[0]]]
    q = [0]
    while True:
        i = q[0]
        if i == 1:
            break
        q = q[1:]
        x = c[i]
        for j in b[i]:
            y = c[j]
            if c[j] is not None and x[0]+1 > y[0]:
                continue
            if y is None:
                q.append(j)
                c[j] = [x[0]+1, []]
            for t in x[1]:
                c[j][1].append(t+[j])
    b2 = [set(x) for x in b]                
    res = max([calc(b2, x) for x in set([tuple(x) for x in c[1][1]])])
    return "%d %d" % (c[1][0]-1, res)

def main(ifile, ofile):
    n = int(ifile.readline())
    for i in range(n):
        ofile.write("Case #%s: %s\n" % (i+1, foo(ifile)))

main(sys.stdin, sys.stdout)

