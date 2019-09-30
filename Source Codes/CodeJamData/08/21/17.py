#!/usr/bin/python

import os, sys

IN = sys.stdin

all = sys.stdin.read().split()
all_pos = -1

def next():
    global all, all_pos
    all_pos += 1
    return int( all[ all_pos ] )

def gen(n, A, B, C, D, x0, y0, M):
    X = x0
    Y = y0
    yield X, Y
    for i in range(n-1):
        X = (A * X + B) % M
        Y = (C * Y + D) % M
        yield X, Y

def run( points ):
    kub = { (0,0) : 0, (0,1) : 0, (0,2) : 0 ,
            (1,0) : 0, (1,1) : 0, (1,2) : 0 ,
            (2,0) : 0, (2,1) : 0, (2,2) : 0 }

    xx = (  ((0,0), (0,1), (0,2)),
            ((1,0), (1,1), (1,2)),
            ((2,0), (2,1), (2,2)),
            ((0,0), (1,0), (2,0)),
            ((0,1), (1,1), (2,1)),
            ((0,2), (1,2), (2,2)),
            ((0,0), (1,1), (2,2)),
            ((0,1), (1,2), (2,0)),
            ((0,2), (1,0), (2,1)),

            ((2,0), (1,1), (0,2)),
            ((1,0), (0,1), (2,2)),
            ((0,0), (2,1), (1,2)) )

    for x,y in points:
        a = x % 3
        b = y % 3
        kub[ (a,b) ] += 1

#    print kub
    ret = 0
    for x in kub.values():
        ret += ( x * (x-1) * (x-2) ) / 6
    
    for i,j,k in xx:
        a,b,c = kub[i], kub[j], kub[k]
        ret += a*b*c
    
    return ret

def main():
    lll = next()

    for xxxx in range(lll):
        n = next()
        A = next()
        B = next()
        C = next()
        D = next()
        x = next()
        y = next()
        M = next()

        points = list( gen( n, A, B, C, D, x, y, M) )

        ret = run( points )

        print "Case #%d: %d" % ( xxxx+1, ret )


main()
