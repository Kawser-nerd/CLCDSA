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

## Input templates
# Line as int
readint = lambda infile: int(infile.readline())
# Line as many ints
readints = lambda infile: (int(s) for s in infile.readline().split())

# Precalculation function
from collections import defaultdict
class SharedData():
    def __init__(self):
        free = defaultdict(lambda: 0)
        surp = defaultdict(lambda: 0)
        for a in xrange(11):
            for b in xrange(a, min(a+3, 11)):
                for c in xrange(a, min(a+3, 11)):
                    total = a + b + c
                    if b - a < 2 and c - a < 2:
                        if free[total] < max(b, c):
                            free[total] = max(b, c)
                    else:
                        if surp[total] < max(b, c):
                            surp[total] = max(b, c)
        self.free = free
        self.surp = surp

# Main processing function
def process(infile, ncase, shared):
    data = list(readints(infile))
    N, S, p = data[:3]
    googlers = data[3:]
    free = 0
    req = 0
    for value in googlers:
        if shared.free[value] >= p:
            free += 1
        elif shared.surp[value] >= p:
            req += 1
    return free + min(req, S)

# Script code
if __name__ == '__main__':
    ## Setup
    # Task letter
    from os.path import basename, splitext
    TASK=splitext(basename(__file__))[0]
    print("Task {}".format(TASK))
    
    ## Precalculation
    print("Precalculation...")
    shared = SharedData()
    print("Precalculation done.")
    
    ## Calculation
    print("Calculation...")
    with open(TASK+".in") as infile:
        with open(TASK+".out",mode="wt") as outfile:
            cases = int(infile.readline())
            for ncase in range(cases):
                print("Case #{nc}".format(nc=ncase+1))
                # Perform all nessesary calculation
                data = process(infile, ncase=ncase, shared=shared)
                outfile.write("Case #{nc}: {data}\n".format(nc=ncase+1,data=data))
    print("Calculation done.")
