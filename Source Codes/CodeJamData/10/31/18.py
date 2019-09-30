#! /usr/bin/env python
import sys, re
import operator as op
# some reading functions
getline = lambda f: f.readline().strip()
gettoken = lambda f: re.split("\s+", getline(f))
getint = lambda f: int(getline(f))
getints = lambda f: map(int, gettoken(f))

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

# vector / geometry
cross = lambda u,v: u[0]*v[1] - u[1]*v[0]
add = lambda u,v: map(op.add, u, v)
sub = lambda u,v: map(op.sub, u, v)
scale = lambda u,s: map(lambda x: x*s, u)
neg = lambda u: map(op.neg, u)
mul = lambda u,v: map(op.mul, u, v)
dot = lambda u,v: sum(mul(u, v))
norm2 = lambda u: dot(u, u)
norm = lambda u: math.sqrt(norm2(u))
dist = lambda u,v: norm(sub(u, v))
dist2 = lambda u,v: norm2(sub(u, v))
def normalize(u):
    d = norm(u)
    if d == 0: return u
    return scale(u, 1.0/d)
turn = lambda u,v,w: cross(sub(v, u), sub(w, v))
straddle = lambda u,v,w,x: turn(u,v,w)*turn(u,v,x) < 0
intersect = lambda u,v,w,x: straddle(u,v,w,x) and straddle(w,x,u,v)



if __name__ == "__main__":
    f = open(sys.argv[1]) # open file

    [N] = getints(f)
    for cases in xrange(0,N): # loop over cases
        ans = 0
        # main

        n = getint(f)
        l = []
        for i in xrange(n):
            a, b = getints(f)
            l.append((a, b))

        inter = 0
        for i, (x, y) in enumerate(l):
            for j, (u, v) in enumerate(l):
                if i == j: break
                s = (x - u) * (y - v) < 0
                if s: inter+= 1
                #if intersect((x, 0), (y, 1), (u, 0), (v, 1)): inter+=1
        ans = inter

        # main
        print "Case #%d: %d"%( cases+1, ans ) # answer output
