#!/usr/bin/env python

from sys import argv
from operator import itemgetter

def shortest_path(pl):
    d = 0
    p = pl[0].copy()
    plast = pl[0].copy()
    while 1 not in p:
        d += 1
        psucc = set()
        for x in plast:
            psucc |= pl[x]
        psucc -= p
        p |= psucc
        plast = psucc
    return d

def solve_s(pl,d):
    rmin = 0
    s = [(0,d,set([0]),pl[0]|set([0]))]
    while s:
        p,d,conquered,reachable = s.pop()
        if 1 in reachable:
            rmin = max(rmin,len(reachable) - len(conquered))
        elif d:
            for x in pl[p]:
                if x not in conquered:
                    nr = reachable | pl[x]
                    if nr != reachable:
                        s.append((x,d-1,conquered|set([x]),nr))
    return rmin

def solve(pl):
    d = shortest_path(pl)
    return d,solve_s(pl,d)

f = open(argv[1],'r')
n = int(f.readline())
for x in xrange(n):
    p,w = map(int,f.readline().split())
    pl = [set() for y in xrange(p)]
    succ = f.readline().split()
    for y in succ:
        z = map(int,y.split(','))
        pl[z[0]].add(z[1])
        pl[z[1]].add(z[0])
    d,r = solve(pl)
    print 'Case #%d: %d %d' % (x+1,d,r)
f.close()
