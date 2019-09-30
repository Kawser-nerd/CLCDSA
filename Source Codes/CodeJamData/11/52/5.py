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
TASK="B"

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
from collections import Counter
from bisect import insort
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
            cards = [int(s) for s in infile.readline().split()][1:]
            values = Counter(cards)
            nums = [values[i] for i in xrange(0, 10002)]
            starts = []
            shortest = 100000
            c = 0
            for i, n in enumerate(nums):
                if n > c:
                    starts += [i] * (n-c)
                if c > n:
                    shortest = min(shortest, i - starts[c-n-1])
                    starts = starts[c-n:]
                c = n
            if len(cards) == 0:
                shortest = 0
            outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=shortest))
print("Calculation done.")
