
import collections
import itertools
import math
import networkx as nx
import numpy as np
import heapq

if __name__ != '__main__':
    import devtools

################################################################################

DAY = 24*60

def read_case(r):
    AC, AJ = r.read_ints()
    CD = r.read_arr(AC)
    JK = r.read_arr(AJ)
    return AC, AJ, CD, JK

def solve_small(case):
    AC, AJ, CD, JK = case
    A = list(sorted([[c, d, 0] for c, d in CD] + [[c, d, 1] for c, d in JK]))
    gaps = [set(), set()]
    hulls = [set(), set()]
    start = None
    for _i in range(3*len(A)):
        i = _i % len(A)
        if A[i][2] == A[i-1][2]:
            new_gap = (A[i-1][1], A[i][0])
            gaps[A[i][2]].add(new_gap)
        else:
            if start is not None:
                new_hull = (start, A[i-1][1])
                hulls[A[i-1][2]].add(new_hull)
            start = A[i][0]
    totals = [0, 0]
    if AC == 0 or AJ == 0:
        hulls[A[0][2]].add((0, DAY))
        totals[A[0][2]] = DAY
        sw = 0
    else:
        sw = 2 * len(hulls[0])
        for who in range(2):
            totals[who] = sum([(d-c+DAY)%DAY for c, d in hulls[who]])
    heaps = [[], []]
    for who in range(2):
        for c, d in gaps[who]:
            heapq.heappush(heaps[who], -((d-c+DAY)%DAY))
    for who in range(2):
        while totals[who] > DAY//2:
            g = heapq.heappop(heaps[who])
            totals[who] += g
            sw += 2
    return sw

def solve_large(case):
    return solve_small(case)

def write_case(w, res):
    w.write_str(res)

################################################################################

class CaseReader(object):
    def __init__(self, f):
        self.f = f

    def __iter__(self):
        def iter():
            T = self.read_int()
            for i in range(1, T+1):
                yield i, read_case(self)
        return iter()

    def read_str(self):
        return next(self.f).strip()

    def read_int(self, b=10):
        return int(self.read_str(), b)

    def read_chrs(self):
        return list(self.read_str())

    def read_digits(self, b=10):
        return [int(x, b) for x in self.read_chrs()]

    def read_strs(self, d=' '):
        return self.read_str().split(d)

    def read_ints(self, b=10, d=' '):
        return [int(x, b) for x in self.read_strs(d)]

    def read_floats(self, d=' '):
        return [float(x) for x in self.read_strs(d)]

    def read_arr(self, rows, read_kind=read_ints, *args, **kwargs):
        return [read_kind(self, *args, **kwargs) for _ in range(rows)]

class ResWriter(object):
    def __init__(self, f, case_reader, solver=solve_small):
        self.f = f
        self.case_reader = case_reader
        self.solver = solver

    def __iter__(self):
        def iter():
            for i, case in self.case_reader:
                res = self.solver(case)
                self.f.write("Case #%d: "%i)
                write_case(self, res)
                yield i, case, res
        return iter()

    @staticmethod
    def _strb(i, b):
        if i == 0:
            return '0'
        s = []
        while i > 0:
            s.append(str(i%b))
            i = i//b
        return ''.join(reversed(s))

    def write_str(self, res, newl=True):
        self.f.write(str(res))
        if newl:
            self.f.write('\n')

    def write_int(self, res, b=10, newl=True):
        self.f.write(self._strb(res, b))
        if newl:
            self.f.write('\n')

    def write_strs(self, res, d=' ', newl=True):
        self.f.write(d.join(str(r) for r in res))
        if newl:
            self.f.write('\n')

    def write_chars(self, res, d='', newl=True):
        self.write_strs(res, d)
        if newl:
            self.f.write('\n')

    def write_ints(self, res, b=10, d=' ', newl=True):
        self.f.write(d.join(self._strb(r, b) for r in res))
        if newl:
            self.f.write('\n')

    def write_arr(self, arr, write_kind, newl=True, *args, **kwargs):
        first = True
        some = False
        for row in arr:
            if first:
                first = False
            else:
                self.f.write('\n')
            write_kind(self, row, newl=False, *args, **kwargs)
            some = True
        if some and newl:
            self.f.write('\n')

if __name__ == '__main__':
    in_fn = 'test-small-attempt0.in'
    out_fn = 'test-small-attempt0.out'
    with open(in_fn, 'r') as fi:
        with open(out_fn, 'w') as fo:
            collections.deque(ResWriter(fo, CaseReader(fi)), 0)
else:
    from run import *
