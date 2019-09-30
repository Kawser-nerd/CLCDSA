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
        pass

    def process(self, infile, ncase):
        ## User code here
        N, total, tgt = infile.readline().strip().split()
        N = int(N)
        total = float(total)
        tgt = float(tgt)
        sources = [[float(s) for s in infile.readline().split()] for i in range(N)]
        hots = [(flow, temp) for (flow, temp) in sources if temp > tgt]
        colds = [(flow, temp) for (flow, temp) in sources if temp < tgt]
        norms = [(flow, temp) for (flow, temp) in sources if temp == tgt]
        total_flow = sum(flow for (flow, temp) in norms)
        heat_plus = sum((temp - tgt) * flow for (flow, temp) in hots)
        heat_minus = sum((tgt - temp) * flow for (flow, temp) in colds)
        if total_flow == 0 and (heat_plus == 0 or heat_minus == 0):
            return "IMPOSSIBLE"
        # ...
        if heat_plus > heat_minus:
            total_flow += sum(flow for (flow, temp) in colds)
            total_amount = heat_minus
            items = [(flow, temp - tgt) for (flow, temp) in hots]
        else:
            total_flow += sum(flow for (flow, temp) in hots)
            total_amount = heat_plus
            items = [(flow, tgt - temp) for (flow, temp) in colds]
        items.sort(key=lambda pair: pair[1])
        for flow, price in items:
            used_flow = min(flow, total_amount / price)
            total_flow += used_flow
            total_amount -= used_flow * price
        return total / total_flow


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
