#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np

if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        R, C = map(int, sys.stdin.readline().split())
        street = [sys.stdin.readline() for i in range(R)]

        lbound,rbound,ubound,bbound = set(),set(),set(),set()
        counter = 0
        for r in range(R):
            for c in range(C):
                if street[r][c] != '.':
                    if street[r][c] == '<':
                        counter = counter + 1
                    lbound.add((r,c))
                    break
            for c in range(C-1,-1,-1):
                if street[r][c] != '.':
                    if street[r][c] == '>':
                        counter = counter + 1
                    rbound.add((r,c))
                    break
        for c in range(C):
            for r in range(R):
                if street[r][c] != '.':
                    if street[r][c] == '^':
                        counter = counter + 1
                    ubound.add((r,c))
                    break
            for r in range(R-1,-1,-1):
                if street[r][c] != '.':
                    if street[r][c] == 'v':
                        counter = counter + 1
                    bbound.add((r,c))
                    break
        print( "Case #{}: {}".format(t+1, counter if len(set.intersection(lbound,rbound,ubound,bbound))==0 else 'IMPOSSIBLE') )