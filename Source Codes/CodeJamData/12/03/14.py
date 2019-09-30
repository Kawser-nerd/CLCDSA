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

# Precalculation of shared data
class SharedData():
    def __init__(self):
        ## User code here
        pass

# Main processing function
def process(infile, ncase, shared):
    ## User code here
    A, B = readints(infile)
    chars = len(str(A))
    pairs = 0
    for n in xrange(A, B+1):
        m = n
        ms = set()
        for i in xrange(1, chars):
            m = (m // 10) + (m%10) * (10 ** (chars - 1))
            if m < n and m >= A and m not in ms:
                pairs += 1
                ms.add(m)
    return pairs

# Script code
if __name__ == '__main__':
    ## Setup
    # Task letter
    from os.path import basename, splitext
    TASK=splitext(basename(__file__))[0]
    print("Task {}".format(TASK))
    from sys import argv
    if len(argv) > 1:
        print("Filename given: {}".format(argv[1]))
        FILE = argv[1][:-3]
    else:
        FILE = TASK
    ## Precalculation
    print("Precalculation...")
    shared = SharedData()
    print("Precalculation done.")
    
    ## Calculation
    print("Calculation...")
    with open(FILE + ".in") as infile:
        with open(FILE + ".out",mode="wt") as outfile:
            cases = int(infile.readline())
            for ncase in range(cases):
                print("Case #{nc}".format(nc=ncase + 1))
                # Perform all nessesary calculation
                data = process(infile, ncase=ncase, shared=shared)
                outfile.write("Case #{nc}: {data}\n".format(
                        nc=ncase + 1,data=data))
    print("Calculation done.")
