#!/usr/bin/python

import sys, re, string, math

def gcd(a,b):
    while a>0:
        (a,b) = (b%a,a)
    return b

def do_one_case(cnum):
    v = map(long, sys.stdin.readline().split())
    assert v[0]+1 == len(v)
    assert v[0]>=2
    g = abs(v[1]-v[2])
    for i in range(3, len(v)):
        g = gcd(g, abs(v[1]-v[i]))
    a = (g - (v[1] % g)) % g
    # print g,v[1], v[1]%g, g-(v[1]%g)
    print "Case #%d: %d" % (cnum, a)


def main():
    N = int(sys.stdin.readline().strip())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
