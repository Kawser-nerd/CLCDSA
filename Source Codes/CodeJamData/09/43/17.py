#!/usr/bin/env python
import sys

def find_crossing(prices):
    res = []
    for i, pi in enumerate(prices):
        x = []
        res.append(x)
        for j, pj in enumerate(prices):
            cross = False
            where = cmp(pi[0], pj[0])
            cross = cross or where == 0 
            cross = cross or any( cmp(a,b) != where for a,b in zip(pi,pj) )
            x.append(cross)
    return res

def min_disjoint(k, cross, unhappy=[], n=0, best = None):
    if best is not None and len(unhappy) >= best: return best
    if n >= k: return len(unhappy)

    un2=unhappy[:]
    for i,u in enumerate(unhappy):
        if u[n]: continue
        u2 = [x or y for x,y in zip(u, cross[n])]
        un2[i] = u2
        best = min_disjoint(k, cross, un2, n+1, best)
        if u2 == u: return best
        un2[i] = u
    best = min_disjoint(k, cross, unhappy+[cross[n]], n+1, best)
    return best

f = sys.stdin
cases = int(f.readline().strip())
for case in range(cases):
    line = map(int, f.readline().strip().split())
    n,k = map(int, line)
    prices = []
    for row in range(n):
        prices.append(  map(int, f.readline().strip().split()) )
    crossing = find_crossing(prices)
    print "Case #%d: %d" % (case+1, min_disjoint(n,crossing))
    
