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
    N, L = inputfile.read_integers()
    good = inputfile.read_strings()
    assert len(good) == N
    bad = inputfile.read_string()
    return N, L, good, bad


def solve(N, L, good, bad):
    if bad in good:
        return None

    if L == 1:
        if bad == "0":
            return ("1?", "1")
        elif bad == "1":
            return ("0?", "0")
        else:
            assert False, bad
    else:
        return ("10" * (L-1) + "?1", "?" * (L-1))


def write(result):
    if result is None:
        print "IMPOSSIBLE"
    else:
        assert sum(map(len, result)) <= 200
        print " ".join(result)


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
