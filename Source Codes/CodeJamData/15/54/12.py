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


from collections import Counter
from math import factorial

# Working class
class Solver(ProblemSolver):
    def precalculate(self):
        ## User code here
        pass

    @staticmethod
    def build_bernoulli_set(value, count):
        result = Counter()
        for i in range(count + 1):
            result[value * i] = (
                factorial(count) // factorial(i) // factorial(count - i))
        return result

    @staticmethod
    def multiset_divide(set1, set2):
        set_quot = Counter()
        set_rem = set1.copy()
        while set_rem:
#            print(len(set1), len(set_rem))
            value = min(set_rem.keys())
            count = set_rem[value]
            set_quot[value] = count
            for (val, cnt) in set2.items():
                key = value + val
                new = set_rem[key] - count * cnt
                if new:
                    set_rem[key] = new
                else:
                    del set_rem[key]
        return set_quot

    @staticmethod
    def find_baseline(values, baseline, prefix=[]):
        if baseline == 0:
            return prefix + values
        if not values:
            return None
        v, *others = values
        if baseline + v <= 0:
            ans = Solver.find_baseline(others, baseline + v, prefix + [-v])
            if ans is not None:
                return ans
        return Solver.find_baseline(others, baseline, prefix + [v])

    def process(self, infile, ncase):
        # User code here
        infile.readline()
        power_values = readints(infile)
        power_counts = readints(infile)
        baseline = power_values[0]
        zero_count = [p for p in range(65) if 2 ** p == power_counts[0]][0]
        power_values = [(v - baseline) for v in power_values]
        power_counts = [(c // 2 ** zero_count) for c in power_counts]
        power_set = Counter({k: v for (k, v) in
                            zip(power_values, power_counts)})
        log_set = Counter()

        while len(power_set) > 1:
            value = sorted(power_set.keys())[1]
            count = power_set[value]
            log_set[value] = count
            bernoulli_set = self.build_bernoulli_set(value, count)
            power_set = self.multiset_divide(power_set, bernoulli_set)

        log_values = sorted(log_set.elements(), reverse=True)
        return ' '.join(str(v) for v in
                        sorted(self.find_baseline(log_values, baseline) +
                               [0] * zero_count))

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
