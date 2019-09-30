#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function
## Library
# @memoized
def memoized(func):
    mem = {}
    def wrapped(*args):
        if args not in mem:
            mem[args] = func(*args)
        return mem[args]
    return wrapped

## Setup
# Task letter
TASK="A"

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
import numpy as np
from scipy.interpolate import interp1d
from scipy.optimize import bisect
#print("Precalculation...")
#print("Precalculation done.")

## Calculation
print("Calculation...")
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            print("Case #{nc}".format(nc=ncase+1))
            # Perform all nessesary calculation
            W, L, U, G = (int(s) for s in infile.readline().split())
            Lp = [[int(s) for s in infile.readline().split()]
                    for i in xrange(L)]
            Lx, Ly = zip(*Lp)
            Up = [[int(s) for s in infile.readline().split()]
                    for i in xrange(U)]
            Ux, Uy = zip(*Up)
            X = np.sort(np.array(list(set(Lx)|set(Ux))))
            Ly = interp1d(Lx, Ly)(X)
            Uy = interp1d(Ux, Uy)(X)
            Y = Uy - Ly
            area = sum( (Y[1:]+Y[:-1])/2 * (X[1:]-X[:-1]) )
            def cumul_area(ax):
                px = 0
                py = 0
                area = 0
                for x, y in zip(X, Y):
                    if x == px:
                        px, py = x, y
                        continue
                    if ax < x:
                        y = py + (y-py)/(x-px)*(ax-px)
                        x = ax
                    area += (x-px)*(y+py)/2
                    px, py = x, y
                    if x == ax:
                        break
                return area
            NAs = np.arange(1, G, dtype='float')*area/G
            points = [bisect(lambda x: cumul_area(x)-NA, 0, W) for NA in NAs]
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data='\n'+'\n'.join(str(p) for p in points)))
print("Calculation done.")
