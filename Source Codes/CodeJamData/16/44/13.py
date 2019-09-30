#!/usr/bin/env python

import sys
ls = sys.stdin.readlines()[1:]

def make(gs, bm):
    g = [[col for col in row] for row in gs]
    n = len(g)
    for i in range(n):
        for j in range(n):
            if bm & (1<<(i*n + j)):
                if g[i][j] == '1':
                    return None
                g[i][j] = '1'
    return g

def count(bm):
    r = 0
    while bm > 0:
        if bm & 1:
            r += 1
        bm >>= 1
    return r

def ok(g):
    n = len(g)
    for col in range(n):
        alt = set()
        nw = 0
        for row in range(n):
            if g[row][col] == '1':
                nw += 1
                for j in range(n):
                    if j != col and g[row][j] == '1':
                        alt.add(j)
        if len(alt) >= nw:
            #print g, col, alt, nw
            return False
    return True
        

C = 1
while ls:
    n = int(ls[0])
    gs = [list(row[0:n]) for row in ls[1:1+n]]
    ls = ls[1+n:]

    ans = 10000000
    for bm in range(2**(n*n)):
        g = make(gs, bm)
        if g is None:
            continue
        if ok(g):
            ans = min(ans, count(bm))

    print "Case #%d: %d" % (C, ans)
    C += 1
