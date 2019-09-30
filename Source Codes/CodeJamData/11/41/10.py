#!/usr/bin/python2
from __future__ import division
### Google Code Jam template
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
#print("Precalculation...")
#print("Precalculation done.")

## Calculation
print("Calculation...")
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            # Perform all nessesary calculation
            X, W, R, t, N = (int(s) for s in infile.readline().split())
            parts = []
            for i in xrange(N):
                B, E, s = (int(s) for s in infile.readline().split())
                X -= E - B
                parts.append((s, E-B))
            parts.append((0, X))
            parts.sort()
            T = 0
            for s, L in parts:
                if t > 0:
                    Tr = min(L / (s + R), t)
                    T += Tr
                    t -= Tr
                    L -= (s + R) * Tr
                if t == 0:
                    T += L / (s + W)
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=T))
print("Calculation done.")
