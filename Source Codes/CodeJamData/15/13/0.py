from fractions import gcd
from collections import *
from sys import stderr
def rg((a,b)):
    g = abs(gcd(a,b))
    assert g
    return a / g, b / g

def sub((a,b),(c,d)):
    return a - c, b - d

def cross((a,b),(c,d)):
    return a * d - b * c

def dot((a,b),(c,d)):
    return a * c + b * d

def quad((a,b)):
    if a > 0:
        if b > 0:
            return 2
        if b < 0:
            return 8
        if b == 0:
            return 1
    if a < 0:
        if b > 0:
            return 4
        if b < 0:
            return 6
        if b == 0:
            return 5
    if a == 0:
        if b > 0:
            return 3
        if b < 0:
            return 7
        if b == 0:
            return 0
    assert False


def cmpr(a,b):
    qa = quad(a)
    qb = quad(b)
    assert qa and qb
    if qa != qb:
        return qa - qb
    return cross(b,a)

def correct(pj,pi):
    x = cross(pj,pi)
    return x < 0

def ilan(p, pts):
    if not pts:
        return 0
    cts = {}
    pts2 = []
    for pt in pts:
        pt = rg(sub(pt,p))
        if pt in cts:
            cts[pt] += 1
        else:
            cts[pt] = 1
            pts2.append(pt)
    pts = pts2
    pts2.sort(cmp=cmpr)
    n = len(pts)
    pts += pts

    mn = 10**100
    j = 0
    ttl = 0
    for i in xrange(n):
        if j <= i:
            j = i+1
            ttl = 0
        while j < i+n and correct(pts[j],pts[i]):
            ttl += cts[pts[j]]
            j += 1
        mn = min(mn, ttl)
        ttl -= cts[pts[i+1]]

    return mn


for cas in xrange(1,1+input()):
    n = input()
    pts = []
    for i in xrange(n):
        x, y = map(int, raw_input().strip().split())
        pts.append((x, y))
    print "Case #%s:" % cas
    print >>stderr, "Case #%s:" % cas
    for i in xrange(n):
        # print >>stderr, "%s of %s" % (i, n)
        print ilan(pts[i], pts[:i] + pts[i+1:])

