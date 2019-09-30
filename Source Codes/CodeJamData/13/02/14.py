#!/usr/bin/python

import sys
import numpy as np

# -------------------------------------------------------------------------------------------------

def all_value(it, values):
    return all( ( x in values for x in it ) )

def any_value(it, values):
    return any( ( x in values for x in it ) )

def arriter(arr):
    n, m = arr.shape
    i=0
    j=0
    for i in range(n):
        for j in range(m):
            yield((i,j), arr[i, j])

# -------------------------------------------------------------------------------------------------

class Problem(object):

    def __init__(self, i, n, m, alines):
        
        self.arr = np.zeros((n, m))

        self.i = i
        self.n, self.m = self.arr.shape

        for i in range(n):
            numbers = map(int, alines[i].split())
            assert(len(numbers) == m)

            self.arr [i, :] = np.array(numbers)
            all_value(self.arr[i,:], range(1, 101))

# -------------------------------------------------------------------------------------------------

class Solver(object):

    def __init__(self, prob):
        self.prob = prob
        self.a = self.prob.arr

    def solve(self):
        a = self.a
        colmax = np.amax(a, axis=0)
        rowmax = np.amax(a, axis=1)

        for pos, val in arriter(a):
            if rowmax[pos[0]] > val and colmax[pos[1]] > val:
                self.res = "NO"
                return

        self.res = "YES"

    def result(self):
        return "Case #%d: %s" % (self.prob.i, self.res)


# -------------------------------------------------------------------------------------------------

def read_problem(f, pcnt):
    n,m = map(int, f.readline().strip().split())
    lines = [ f.readline().strip() for i in range(n) ]
    return Problem(pcnt, n, m, lines)

fin = open(sys.argv[1], "r")
fout = open("out.txt", "w")

N = int(fin.readline())
for i in range(N):
    p = read_problem(fin, i+1)
    s = Solver(p)
    s.solve()
    fout.write("%s\n" % s.result())



