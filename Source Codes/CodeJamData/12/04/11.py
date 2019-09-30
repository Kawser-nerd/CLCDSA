#!/usr/bin/python

import sys, re, string, math, fractions, itertools

from fractions import Fraction, gcd
fff = Fraction.from_float
quarter = Fraction(1, 4)
half = Fraction(1, 2)

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())



def do_one_case(cnum):
    (H, W, D) = rdints()
    hom = []
    for i in range(H):
        x = rdline()
        assert len(x)==W
        assert re.match("#[#.X]*#$", x)
        hom.append(x)
    assert hom[0] == W*"#"
    assert hom[H-1] == hom[0]
    assert re.match("[#.]*X[#.]*$", "".join(hom))
    for r0 in range(H):
        c0 = hom[r0].find("X")
        if c0>=0: break
    assert c0>=0

    nX = 0
    nhash = 0
    for s in hom:
        nX += s.count("X")
        nhash += s.count("#")
    assert nX==1

    if nhash != 2*(H+W) - 4:
        print "Case #%d: Not small" % (cnum,)
        return

    h = H-2
    w = W-2
    h2 = 2*h
    w2 = 2*w
    nh = 4 + int(math.ceil(float(D)/h2))
    nw = 4 + int(math.ceil(float(D)/w2))
    pts = [ (r0,c0), (1-r0,c0), (r0,1-c0), (1-r0,1-c0) ]
    pts2 = [ (r + n*h2, c + m*w2) for (r,c) in pts for n in range(-nh,nh) for m in range(-nw,nw) ]
    pts3 = [ (r-r0, c-c0) for (r,c) in pts2 if r!=r0 or c!=c0 ]
    pts4 = [ (r,c) for (r,c) in pts3 if r**2 + c**2 <= D**2 ]
    #print sorted(pts4)
    pts5 = set([ (r/abs(gcd(r,c)), c/abs(gcd(r,c))) for (r,c) in pts4 ])
    #print sorted(pts5)
    
    N = len(pts5)

    print "Case #%d: %d" % (cnum, N)




















def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
