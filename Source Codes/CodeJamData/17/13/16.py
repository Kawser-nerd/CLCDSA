#! /usr/bin/python2.7

INF = 1e16
cache = {}
def inner_solve(Hd, Ad, Hk, Ak, B, D, org_Hd):
    if (Hd, Ad, Hk, Ak) in cache:
        return cache[Hd, Ad, Hk, Ak]
    if Hd <= 0:
        return INF
    if Ad >= Hk:
        return 1
    cache[Hd, Ad, Hk, Ak] = INF
    best = min(inner_solve(Hd - Ak, Ad, Hk - Ad, Ak, B, D, org_Hd), 
               inner_solve(Hd - Ak, Ad + B, Hk, Ak, B, D, org_Hd))
    if Ak > 0:
        best = min(best, inner_solve(Hd - max(0, Ak - D), Ad, Hk, max(0, Ak - D), B, D, org_Hd))
    if Hd < org_Hd - Ak:
        best = min(best, inner_solve(org_Hd - Ak, Ad, Hk, Ak, B, D, org_Hd))
    cache[Hd, Ad, Hk, Ak] =  1 + best
    return cache[Hd, Ad, Hk, Ak]

def solve(Hd, Ad, Hk, Ak, B, D):
    global cache
    cache = {}
    rv = inner_solve(Hd, Ad, Hk, Ak, B, D, Hd)
    return rv if rv < INF else "IMPOSSIBLE"

import sys
f = sys.stdin
# f = open("q3_example.in")
T = int(f.readline())
for i in xrange(1, T + 1):
    Hd, Ad, Hk, Ak, B, D = map(int, f.readline().split())
    print "Case #%d: %s" % (i, solve(Hd, Ad, Hk, Ak, B, D))