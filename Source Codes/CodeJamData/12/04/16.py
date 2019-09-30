#!/usr/bin/env python

import pdb
import re
import sys

INPUT = "tiny"

INPUT = "D-small-attempt0.in.txt"

def debug(*args):
    pass #print str(args)

if 0:
    def debug(*args):
        sys.stderr.write(''.join(str(s) for s in args) + "\n")

def gcd(a,b):
    a,b = abs(a), abs(b)
    while 1:
        if a > b: a,b=b,a
        if a < 1: return b
        a, b = b%a, a

def do_simple_trial(H, W, D, X, Y):
    debug("W, H, X, Y, D =", W, H, X, Y, D)
    x = 2*X - 1
    y = 2*Y - 1
    w = 2 * (W - 2)
    h = 2 * (H - 2)
    def x_coords():
        max_x = int(D/w)+3
        for i in xrange(-max_x, max_x):
            yield i * w
            yield i * w + x
    def y_coords():
        max_y = int(D/h)+3
        for i in xrange(-max_y, max_y):
            yield i * h
            yield i * h + y
    l = []
    max_d = D * D
    for x0 in x_coords():
        for y0 in y_coords():
            if y0 == x0 == 0: continue
            d = x0 * x0 + y0 * y0
            if d <= max_d:
                l.append((x0*x0+y0*y0,x0,y0))
    l.sort()
    s = set()
    for d, x0, y0 in l:
        g = gcd(x0,y0)
        x0 /= g
        y0 /= g
        s.add((x0, y0))
    debug("s = %s" % s, len(s))
    return len(s)

def do_trial(H, W, D, lines):
    for j in range(H):
        l = lines[j]
        v = l.find('X')
        if v > -1:
            x, y = v, j
    return do_simple_trial(H, W, D, x, y)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    debug("i=%s" % i)
    H, W, D = [int(x) for x in f.readline()[:-1].split()]
    lines = []
    for j in range(H):
        lines.append(f.readline()[:-1])
    v = do_trial(H,W,D,lines)
    print "Case #%d: %s" % (i+1, v)
