#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys
from multiprocessing import Pool
from z3 import *
from collections import namedtuple

verbose = True

RightLeft = namedtuple("RightLeft", "right left")


def read(inputfile):
    R, C = inputfile.read_integers()
    couples = inputfile.read_integers()
    assert 2 * (R + C) == len(couples)
    return R, C, couples


def solve(rows, columns, couples):
    R, C = rows, columns
    s = z3.Solver()

    couple_id = {}
    for i in xrange(R+C):
        ia = i*2
        ib = i*2+1
        couple_id[couples[ia]-1] = i
        couple_id[couples[ib]-1] = i

    #print couple_id

    grid = {
        (r, c): (
            Bool("/[{}, {}]".format(r, c)),
            RightLeft(
                Int("left[{}, {}]".format(r, c)),
                Int("right[{}, {}]".format(r, c))
            )
        )
        for r in xrange(rows)
        for c in xrange(columns)
    }

    for (r, c), (sym_diag_up, sym_owner) in grid.items():
        s.add(sym_owner.left >= 0,  sym_owner.left < R+C)
        s.add(sym_owner.right >= 0, sym_owner.right < R+C)

        if (r - 1, c) in grid:
            x_diag_up, x_owner = grid[r-1, c]
            up = If(x_diag_up, x_owner.right, x_owner.left)
        else:
            up = couple_id[c]

        if (r, c + 1) in grid:
            x_diag_up, x_owner = grid[r, c+1]
            right = x_owner.left
        else:
            right = couple_id[C+r]

        if (r + 1, c) in grid:
            x_diag_up, x_owner = grid[r+1, c]
            down = If(x_diag_up, x_owner.left, x_owner.right)
        else:
            down = couple_id[C+R+C-1-c]

        if (r, c - 1) in grid:
            x_diag_up, x_owner = grid[r, c-1]
            left = x_owner.right
        else:
            left = couple_id[C+R+C+R-1-r]

        s.add(If(
            sym_diag_up,
            And(
                sym_owner.left == left,
                sym_owner.left == up,
                sym_owner.right == right,
                sym_owner.right == down
            ),
            And(
                sym_owner.left == left,
                sym_owner.left == down,
                sym_owner.right == right,
                sym_owner.right == up
            )
        ))

    # Solve the system
    if s.check() == sat:
        m = s.model()
        res = [[None] * columns for _ in xrange(rows)]
        for r in xrange(rows):
            for c in xrange(columns):
                x_diag_up, x_owner = grid[r, c]
                diag_up = is_true(m[x_diag_up])
                if diag_up:
                    res[r][c] = "/"
                else:
                    res[r][c] = "\\"
        rr = ["".join(row) for row in res]
        assert len(rr[0]) == C
        assert len(rr) == R
        return rr
    else:
        return None


def write(result):
    if result is None:
        print "IMPOSSIBLE"
    else:
        print "\n".join(result)


def main(parallel=True, _verbose=True):
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
        print "Case #{}:".format(i + 1)
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
