#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function

from math import factorial


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
readints = lambda infile: [int(s) for s in infile.readline().split()]


# Base class
class ProblemSolver(object):
    def __init__(self):
        self.precalculate()

    def precalculate(self):
        raise NotImplementedError

    def process(self, infile, ncase):
        raise NotImplementedError

    def run(self, infile, outfile):
        cases = int(infile.readline())
        for ncase in range(cases):
            print("Case #{nc}".format(nc=ncase + 1))
            # Perform all nessesary calculation
            data = self.process(infile, ncase=ncase)
            outfile.write("Case #{nc}: {data}\n".format(
                nc=ncase + 1, data=data))


# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        self.layer_cum_volumes = [2 * num ** 2 + 3 * num + 1
                                  for num in xrange(1000)]

    def process(self, infile, ncase):
        ## User code here
        N, X, Y = readints(infile)
        site_layer = (Y + abs(X)) // 2
        complete_layer, complete_volume = (
            max(
                (layer, volume)
                for layer, volume in enumerate(self.layer_cum_volumes)
                if volume <= N)
        )
        # Not in the latest layer
        if site_layer <= complete_layer:
            return 1.0
        elif site_layer > complete_layer + 1:
            return 0.0
        # In the latest layer
        extra = N - complete_volume
        side = complete_layer * 2 + 2
        displacement = abs(X)
        level = side - displacement
        if extra > side + level:
            return 1.0
        if not displacement:
            return 0.0
        # Not guaranteed to fill
        return sum(
            factorial(extra) / (2 ** extra * factorial(i) * factorial(extra - i))
            for i in range(level + 1, extra + 1))


# Script code
if __name__ == '__main__':
    ## Setup
    # Task letter
    from os.path import basename, splitext
    TASK = splitext(basename(__file__))[0]
    print("Task {}".format(TASK))
    from sys import argv
    if len(argv) > 1:
        print("Filename given: {}".format(argv[1]))
        FILE = splitext(argv[1])[0]
    else:
        FILE = TASK
    ## Precalculation
    print("Initialization...")
    solver = Solver()
    print("Initialization done.")
    ## Calculation
    print("Calculation...")
    with open(FILE + ".in") as infile:
        with open(FILE + ".out", mode="wt") as outfile:
            solver.run(infile, outfile)
    print("Calculation done.")
