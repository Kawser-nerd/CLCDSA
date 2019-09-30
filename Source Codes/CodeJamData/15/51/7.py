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

def seq_iter(V0, Av, Cv, Mv, count):
    for i in range(count):
        yield V0
        V0 = (V0 * Av + Cv) % Mv

def fill_minmax(S, M, iS, xS, i):
    manager = M[i]
    if manager is None:
        iS[i] = S[i]
        xS[i] = S[i]
    else:
        if iS[manager] is None:
            fill_minmax(S, M, iS, xS, manager)
        iS[i] = min(S[i], iS[manager])
        xS[i] = max(S[i], xS[manager])

# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    def process(self, infile, ncase):
        ## User code here
        N, D = readints(infile)
        S0, As, Cs, Rs = readints(infile)
        salaries = list(seq_iter(S0, As, Cs, Rs, N))
        M0, Am, Cm, Rm = readints(infile)
        managers = list(seq_iter(M0, Am, Cm, Rm, N))
        managers = [m % i if i else None for (i, m) in enumerate(managers)]
        min_salaries = [None] * N
        max_salaries = [None] * N
        for i in range(N):
            fill_minmax(salaries, managers, min_salaries, max_salaries, i)
        min_salaries, max_salaries = zip(*[
            (i, x) for (i, x) in zip(min_salaries, max_salaries) if x - i <= D])
        starts = sorted([m - D for m in max_salaries])
        ends = sorted(min_salaries)
        starts = [(v, '0+') for v in starts]
        ends = [(v, '1-') for v in ends]
        edges = sorted(starts + ends)
        e_counts = []
        count = 0
        for (v, c) in edges:
            if c == '0+':
                count += 1
            else:
                count -= 1
            e_counts.append(count)
        print(e_counts)
        return(max(e_counts))





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
