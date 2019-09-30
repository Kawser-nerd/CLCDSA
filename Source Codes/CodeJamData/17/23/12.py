#!/usr/bin/python

from __future__ import division
from gcj import *

# boolean flags, reachable via OPTS.flagname. Space separated in string
FLAGS = ''

def case():
    N, Q = ints()
    E = [None] * N
    S = [None] * N
    for i in range(N):
        E[i], S[i] = ints()
    grid = []
    for i in range(N):
        grid.append(ints())

    #pprint(grid)

    grid2 = []
    for i in range(N):
        grid2.append(calc(grid, i, E[i], S[i]))
    #pprint(grid2)

    res = []
    for i in range(Q):
        U, V = ints()
        res.append(calc2(grid2, U-1, V-1))

    return ' '.join('%f' % x for x in res)

def calc(grid, start, E, S):
    N = len(grid)

    e = [-1] * N

    e[start] = E
    pq = set()
    pq.add(start)
    done = set()
    while pq:
        v = max(pq, key=lambda k: e[k])
        pq.remove(v)
        assert v not in done
        done.add(v)
        if e[v] < 0:
            break
        for n, d in enumerate(grid[v]):
            if d < 0: continue
            newe = e[v] - d
            #print "We kunen van %d naar %d in %d, over %d" % (v, n, d, newe)
            if newe > e[n]:
                e[n] = newe
                pq.add(n)
    for i in range(N):
        if e[i] >= 0:
            e[i] = (E-e[i])/S
    return e

def calc2(grid, U, V):
    N = len(grid)

    t = [1e100] * N

    t[U] = 0
    pq = set()
    pq.add(U)
    done = set()
    while pq:
        v = min(pq, key=lambda k: t[k])
        pq.remove(v)
        assert v not in done
        done.add(v)
        if v == V:
            return t[v]
        for n, d in enumerate(grid[v]):
            if d < 0: continue
            newt = t[v] + d
            #print "We kunen van %d naar %d in %f, over %d" % (v, n, d, newt)
            if newt < t[n]:
                #print "Dit is beter dan %f" % t[n]
                t[n] = newt
                pq.add(n)
    huh

if __name__ == '__main__':
    main()
