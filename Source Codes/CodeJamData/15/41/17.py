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
        R, C = readints(infile)
        grid = [infile.readline().strip() for i in range(R)]
        counts = [[0] * C for i in range(R)]
        bads = [[False] * C for i in range(R)]
        for i in range(R):
            for j in range(C):
                if grid[i][j] != '.':
                    break
            else:
                continue
            counts[i][j] += 1
            if grid[i][j] == '<':
                bads[i][j] = True
        for i in range(R):
            for j in reversed(range(C)):
                if grid[i][j] != '.':
                    break
            else:
                continue
            counts[i][j] += 1
            if grid[i][j] == '>':
                bads[i][j] = True
        for j in range(C):
            for i in range(R):
                if grid[i][j] != '.':
                    break
            else:
                continue
            counts[i][j] += 1
            if grid[i][j] == '^':
                bads[i][j] = True
        for j in range(C):
            for i in reversed(range(R)):
                if grid[i][j] != '.':
                    break
            else:
                continue
            counts[i][j] += 1
            if grid[i][j] == 'v':
                bads[i][j] = True
        if any(4 in line for line in counts):
            return "IMPOSSIBLE"
        return sum(line.count(True) for line in bads)


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
