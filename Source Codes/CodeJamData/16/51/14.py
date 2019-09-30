#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys
from multiprocessing import Pool
#from pulp import *
#from z3 import *
from collections import namedtuple

verbose = True


def read(inputfile):
    S = inputfile.read_string()
    return (S,)


mem = {}

def calculate(s):
    assert len(s) % 2 == 0
    if len(s) == 0:
        return 0

    if s in mem:
        return mem[s]

    start = s[0]
    i = 1
    best = 0
    while i < len(s):
        end = s[i]
        #
        tot = 0
        if start == end:
            tot += 10
        else:
            tot += 5
        tot += calculate(s[1:i])
        tot += calculate(s[i+1:])
        if tot > best:
            best = tot
        #
        i += 2

    mem[s] = best
    return best


def solve(s):
    global mem
    mem = {}
    return calculate(s)


def write(result):
    print result


def main(parallel, verbose):
    globals()["verbose"] = verbose

    # Read
    inputfile = FileParser()
    T = inputfile.read_int()
    log("Solving", T, "test cases")
    test_cases = [read(inputfile) for _ in xrange(T)]

    # Solve
    if parallel:
        process_pool = Pool(processes=4)
        test_results = process_pool.map_async(solve_data, test_cases).get(9999999)
    else:
        test_results = map(solve_data, test_cases)

    # Write
    for i, result in enumerate(test_results):
        print "Case #{}:".format(i + 1),
        write(result)


def solve_data(data):
    res = solve(*data)
    if verbose:
        sys.stderr.write(".")
        sys.stderr.flush()
    return res


def log(*args):
    if verbose:
        print >> sys.stderr, " ".join(map(str, args))


class FileParser(object):
    """Read numbers/strings from file (or stdin by default), one line by one.

    Example:
        inputfile = FileParser()
        # Read a line of 5 integers
        R, S, U, P, M = inputfile.readIntegers()
        inputfile.close()
    """

    def __init__(self, filepath=None):
        if filepath is None:
            self.fd = sys.stdin
        else:
            self.fd = open(filepath)

    def read_lines(self):
        return self.fd.readlines()

    def read_string(self):
        return self.fd.readline().rstrip()

    def read_strings(self):
        return [x for x in self.read_string().split()]

    def read_int(self):
        return int(self.fd.readline())

    def read_integers(self):
        return [int(x) for x in self.fd.readline().split()]

    def read_float(self):
        return float(self.fd.readline())

    def read_floats(self):
        return [float(x) for x in self.fd.readline().split()]

    def close(self):
        if self.fd is not sys.stdin:
            self.fd.close()
        self.fd = None


if __name__ == "__main__":
    main("-s" not in sys.argv, "-q" not in sys.argv)
