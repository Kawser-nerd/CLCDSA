#!/usr/bin/python2
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function

from collections import defaultdict
import heapq


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
        N = readint(infile)
        values = set(range(1, N + 1))
        A = readints(infile)
        B = readints(infile)
        # Build partial order
        less = defaultdict(lambda: set())
        for i, x in enumerate(A):
            prev = None
            for j, y in enumerate(A[:i]):
                if y >= x:
                    less[j].add(i)
                if y == x - 1:
                    prev = j
            if prev is not None:
                less[i].add(prev)
        Br = B[::-1]
        for i, x in enumerate(Br):
            prev = None
            for j, y in enumerate(Br[:i]):
                if y >= x:
                    less[N - j - 1].add(N - i - 1)
                if y == x - 1:
                    prev = j
            if prev is not None:
                less[N - i - 1].add(N - prev - 1)
        # Linearize
        sequence = []
        active = sorted(i for i in range(N) if not less[i])
        for i in active:
            del less[i]
        while active:
            current = heapq.heappop(active)
            sequence.append(current)
            for tgt, deps in list(less.items()):
                if current in deps:
                    deps.remove(current)
                if not deps:
                    del less[tgt]
                    heapq.heappush(active, tgt)
        # Map back
        result = [None] * N
        for i, v in enumerate(sequence):
            result[v] = i
        return ' '.join(str(i + 1) for i in result)


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
