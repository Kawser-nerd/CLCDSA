#! /usr/bin/env python
import sys, re
# some reading functions
getline = lambda f: f.readline().strip()
gettoken = lambda f: re.split("\s+", getline(f))
getint = lambda f: int(getline(f))
getints = lambda f: map(int, gettoken(f))
getflo = lambda f: float(getline(f))
getflos = lambda f: map(float, gettoken(f))

# number theory / combinatorics
product = lambda l: reduce(lambda x,y: x*y, l) if l else 1
factorial = lambda n: product(xrange(n, 1, -1))
nPr = lambda n, r: product(xrange(n,n-r,-1))
nCr = lambda n, r: nPr(n, r) / factorial(r)
nMr = lambda l: factorial(sum(l)) / product(map(factorial,l))
gcd = lambda x,y: gcd(y, x%y) if y != 0 else x
lcm = lambda x,y: x * y / gcd(x, y)
def gcd2(a, b):
    if b == 0: return (a, 1, 0)
    (d,x,y) = gcd2(b, a % b)
    return (d, y, x - a / b * y)

# lazy but hard to use vector ops                                                                                               
import operator as op
from math import acos, pi, sin, sqrt


add = lambda u,v: map(op.add, u, v)
sub = lambda u,v: map(op.sub, u, v)
scalev = lambda u,s: map(lambda x: x*s, u)
neg = lambda u: map(op.neg, u)
mul = lambda u,v: map(op.mul, u, v)
dot = lambda u,v: sum(mul(u, v))
norm2 = lambda u: dot(u, u)
norm = lambda u: sqrt(norm2(u))
dist = lambda u,v: norm(sub(u, v))
dist2 = lambda u,v: norm2(sub(u, v))
cross = lambda u,v: [u[1]*v[2] - u[2]*v[1],
                     u[2]*v[0] - u[0]*v[2],
                     u[0]*v[1] - u[1]*v[0]]
normalized = lambda u: scalev(u, 1.0/norm(u)) if norm(u) > 0.00001 else u



def quad(a, b, c):
    e = -0.5 * b / a
    d = b * b - 4 * a * c
    if d == 0: return [e]
    if d < 0: return []
    d *= 0.5 / a

    return [e + d, e - d]
    

def sector(c, r, a):
    A = a * r * r
    tA = 0.5 * r * r * sin(2 * a)
    return A - tA

if __name__ == "__main__":
    f = open(sys.argv[1]) # open file

    [N] = getints(f)
    for cases in xrange(0,N): # loop over cases
        ans = 0
        # main

        n, m = getints(f)
        P = [getflos(f) for i in xrange(n)]
        Q = [getflos(f) for i in xrange(m)]
        A = [0 for i in xrange(m)]

        for qi, q in enumerate(Q):
            r = [dist(q, p) for p in P]
            # N = 2, small case
            dt = dist(P[0], P[1])
            if dt > r[0] + r[1]: 
                A[qi] = 0
            else:
                ang1 = dot(normalized(sub(q, P[0])), normalized(sub(P[1], P[0])))
                ang1 = acos(ang1)
                ang2 = dot(normalized(sub(q, P[1])), normalized(sub(P[0], P[1])))
                ang2 = acos(ang2)

                A[qi] = sector(P[0], r[0], ang1) + sector(P[1], r[1], ang2)
                
        # main
        #print "Case #%d: %d"%( cases+1, ans ) # answer output
        print "Case #%d:"%( cases+1 ), # answer output
        for a in A:
            print a, 
        print 
