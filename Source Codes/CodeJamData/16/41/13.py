#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys
from multiprocessing import Pool
import os

verbose = True


def read(inputfile):
    N, R, P, S = inputfile.read_integers()
    return N, R, P, S


def generate(n, winner):
    P, R, S = (0, 1, 2)
    if winner == "P":
        count = [1, 0, 0]
    elif winner == "R":
        count = [0, 1, 0]
    elif winner == "S":
        count = [0, 0, 1]
    else:
        assert False
    res = winner

    for _ in xrange(n):
        # P, R, S
        count = [
            count[P] + count[S],
            count[R] + count[P],
            count[S] + count[R]
        ]
        res = "".join([
            "PR" if x == "P" else
            "RS" if x == "R" else
            "PS" if x == "S" else None
            for x in res
        ])

    return tuple(count), res


def order(res):
    l = len(res)
    if l == 1:
        return res
    a, b = res[:l//2], res[l//2:]
    a, b = order(a), order(b)
    if a <= b:
        return a + b
    else:
        return b + a

def solve(n, r, p, s):
    count = (p, r, s)

    res = []
    for winner in "PRS":
        count_p, res_p = generate(n, winner)
        if count_p == count:
            res.append(order(res_p))

    if len(res):
        x = min(res)
        assert r == x.count("R")
        assert p == x.count("P")
        assert s == x.count("S")
        return x
    else:
        return None


def write(result):
    if result is None:
        print "IMPOSSIBLE"
    else:
        print result


def main(parallel=False, _verbose=True):
    global verbose
    verbose = _verbose

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
    main("-p" in sys.argv, "-q" not in sys.argv)
