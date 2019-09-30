#!/usr/bin/python3
### Google Code Jam template
# Futures
from __future__ import division
from __future__ import with_statement
from __future__ import print_function

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
        city_count, path_count = readints(infile)
        endurances, speeds = zip(*[readints(infile) for i in range(city_count)])
        distances = [readints(infile) for i in range(city_count)]
        paths = [readints(infile) for i in range(path_count)]

        # First we need to switch from km-based to time-based distance matrix
        travel_times = []
        for index, (endurance, speed) in enumerate(zip(endurances, speeds)):
            cumulative_distances = [-1] * city_count
            queue = [(0, index)]
            processed = set()
            while queue:
                distance, index = heapq.heappop(queue)
                if index in processed:
                    continue
                if distance > 0:
                    cumulative_distances[index] = distance
                processed.add(index)
                for i in range(city_count):
                    if i in processed:
                        continue
                    if distances[index][i] == -1:
                        continue
                    next_distance = distance + distances[index][i]
                    if next_distance <= endurance:
                        heapq.heappush(queue, (next_distance, i))
            travel_times.append([d / speed if d != -1 else -1 for d in cumulative_distances])
        # Ok, we're time-based, now let's search for the best paths
        results = []
        for (start, end) in paths:
            total_times = [-1] * city_count
            queue = [(0, start - 1)]
            processed = set()
            while queue:
                time, index = heapq.heappop(queue)
                if index in processed:
                    continue
                total_times[index] = time
                processed.add(index)
                for i in range(city_count):
                    if i in processed:
                        continue
                    if travel_times[index][i] == -1:
                        continue
                    next_time = time + travel_times[index][i]
                    heapq.heappush(queue, (next_time, i))
            results.append(total_times[end - 1])
        return ' '.join([str(t) for t in results])

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
