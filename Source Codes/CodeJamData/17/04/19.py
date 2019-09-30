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
        # Input
        size, count = readints(infile)
        models = {}
        for i in range(count):
            model, r, c = infile.readline().split()
            models[(int(r) - 1, int(c) - 1)] = model

        # Part 1: straight-block markers
        straight_blocks = {pos for (pos, model) in models.items() if model in ['o', 'x']}
        rows = set(range(size))
        cols = set(range(size))
        for (r, c) in straight_blocks:
            rows.remove(r)
            cols.remove(c)
        while rows and cols:
            straight_blocks.add((rows.pop(), cols.pop()))

        # Part 2: diagonal-block markers
        diagonal_blocks = {pos for (pos, model) in models.items() if model in ['o', '+']}
        dsums = set(range(-size, size + 1))
        ddifs = set(range(-size, size + 1))
        for (r, c) in diagonal_blocks:
            dsums.remove(r + c - size + 1)
            ddifs.remove(r - c)
        dsum_list = sorted(dsums, key=abs)
        ddif_list = sorted(ddifs, key=abs)
        for s in dsum_list[::-1]:
            if s not in dsums:
                continue
            for d in ddif_list[::-1]:
                if d not in ddifs:
                    continue
                if (s + d + size - 1) % 2:
                    continue  # Wrong color, there's no intersection cell
                r = (s + d + size - 1) // 2
                c = (s - d + size - 1) // 2
                if r < 0 or c < 0 or r >= size or c >= size:
                    continue  # Intersection outside the board
                dsums.remove(s)
                ddifs.remove(d)
                diagonal_blocks.add((r,c))
                break

        # Position ready, preparing reply
        style = len(straight_blocks) + len(diagonal_blocks)
        edits = []
        for (r, c) in straight_blocks.union(diagonal_blocks):
            if (r, c) in straight_blocks and (r, c) in diagonal_blocks:
                model = 'o'
            elif (r, c) in straight_blocks:
                model = 'x'
            else:
                model = '+'
            if model != models.get((r, c), ''):
                edits.append("{} {} {}".format(model, r+1, c+1))
        return '\n'.join(["{} {}".format(style, len(edits))] + edits)



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
