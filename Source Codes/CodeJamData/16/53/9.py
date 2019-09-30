#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys
from multiprocessing import Pool
#from pulp import *
#from z3 import *
from collections import namedtuple
import math

verbose = True


def read(inputfile):
    N, S = inputfile.read_integers()
    ast = []
    for _ in range(N):
        x, y, z, vx, vy, vz = inputfile.read_floats()
        ast.append((x, y, z))
    return N, S, ast


class UnionFind:
    """Union-find data structure.

    Each unionFind instance X maintains a family of disjoint sets of
    hashable objects, supporting the following two methods:

    - X[item] returns a name for the set containing the given item.
      Each set is named by an arbitrarily-chosen one of its members; as
      long as the set remains unchanged it will keep the same name. If
      the item is not yet part of a set in X, a new singleton set is
      created for it.

    - X.union(item1, item2, ...) merges the sets containing each item
      into a single larger set.  If any item is not yet part of a set
      in X, it is added to X as one of the members of the merged set.
    """

    def __init__(self):
        """Create a new empty union-find structure."""
        self.weights = {}
        self.parents = {}

    def __getitem__(self, object):
        """Find and return the name of the set containing the object."""

        # check for previously unknown object
        if object not in self.parents:
            self.parents[object] = object
            self.weights[object] = 1
            return object

        # find path of objects leading to the root
        path = [object]
        root = self.parents[object]
        while root != path[-1]:
            path.append(root)
            root = self.parents[root]

        # compress the path and return
        for ancestor in path:
            self.parents[ancestor] = root
        return root

    def __iter__(self):
        """Iterate through all items ever found or unioned by this structure."""
        return iter(self.parents)

    def union(self, *objects):
        """Find the sets containing the objects and merge them all."""
        roots = [self[x] for x in objects]
        heaviest = max([(self.weights[r],r) for r in roots])[1]
        for r in roots:
            if r != heaviest:
                self.weights[heaviest] += self.weights[r]
                self.parents[r] = heaviest


def euclid(a, b):
    xa, ya, za = a
    xb, yb, zb = b
    return math.sqrt((xa-xb)**2 + (ya-yb)**2 + (za-zb)**2)

def solve(N, S, ast):
    dist = []
    for ia, a in enumerate(ast):
        for ib, b in enumerate(ast):
            if ia == ib:
                continue
            dist.append((euclid(a, b), ia, ib))

    dist = sorted(dist)

    uf = UnionFind()

    for last_dist, ia, ib in dist:
        uf.union(ia, ib)

        if uf[0] == uf[1]:
            return last_dist

    assert False


def write(result):
    print "{:.10f}".format(result)


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
