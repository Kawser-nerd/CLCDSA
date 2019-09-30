#!/usr/bin/env python

import sys, math

def main(argv):
    n = int(sys.stdin.readline())
    for i in range(1,n+1):
        line = sys.stdin.readline()
        L,P,C = map(int,line.split(" "))
        
        res = 0

        L *= C

        while (L < P):
            L *= C
            C *= C
            res += 1

        print("Case #%d: %d" % (i, res))

main(sys.argv)
