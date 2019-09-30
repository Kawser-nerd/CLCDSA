#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
from string import ascii_lowercase
from string import ascii_uppercase
from fractions import Fraction, gcd
from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
getcontext().prec = 100
sys.setrecursionlimit(1500)

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] != "CPython":  # PyPy?
    raw_input = lambda: sys.stdin.readline().rstrip()
pr = lambda *args: sys.stdout.write(" ".join(str(x) for x in args) + "\n")
epr = lambda *args: sys.stderr.write(" ".join(str(x) for x in args) + "\n")
die = lambda *args: pr(*args) ^ exit(0)

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"

class BipartiteMatching(object):
    def __init__(self, V1, V2):
        self.V1first = 0
        self.V1last = V1 - 1
        self.V2first = V1
        self.V2last = V1 + V2 - 1
        self.edges = defaultdict(list)

        self.pair = {v: None for v in xrange(self.V1first, self.V1last + 1)}
        self.visited = set()
        self.satur = set()

    def add_edge(self, a, b):
        b += self.V2first
        self.edges[a].append(b)
        self.edges[b].append(a)

    def left(self, v):
        return self.V1first <= v <= self.V1last

    def dfs(self, p):
        self.visited.add(p)
        if self.left(p):
            if self.pair[p] is not None:
                r = self.pair[p]
                if r in self.visited:
                    return
                return self.dfs(r)

        for l in self.edges[p]:
            if l in self.visited:
                continue
            if self.pair[l] is None or self.dfs(l):
                self.pair[l] = p
                self.satur.add(p)
                return True

    def get_max(self):
        for v in xrange(self.V2first, self.V2last + 1):
            if v in self.satur:
                continue
            self.visited = set()
            self.dfs(v)
        return sum(1 for v in self.pair.values() if v)


def brute(lst):
    ans = 0
    for orig in product(range(2), repeat=len(lst)):
        ws1 = set()
        ws2 = set()
        for i, (w1, w2) in enumerate(lst):
            if orig[i]:
                ws1.add(w1)
                ws2.add(w2)
        for i, (w1, w2) in enumerate(lst):
            if not orig[i]:
                if w1 not in ws1 or w2 not in ws2:
                    break
        else:
            ans = max(ans, len(lst) - sum(orig))
    return ans


def solve(lst):
    ws1 = set()
    ws2 = set()
    for w1, w2 in lst:
        ws1.add(w1)
        ws2.add(w2)
    ws1 = list(ws1)
    ws2 = list(ws2)

    BP = BipartiteMatching(len(ws1), len(ws2))
    for w1, w2 in lst:
        BP.add_edge(ws1.index(w1), ws2.index(w2))
    maxm = BP.get_max()
    # print >>sys.stderr, "WS1", ws1
    # print >>sys.stderr, "WS2", ws2
    # print >>sys.stderr, "WS2", lst
    # print >>sys.stderr, "MATCH", maxm
    orig = len(ws1) + len(ws2) - maxm
    return len(lst) - orig

T = read_int()
for t in xrange(1, T + 1):
    print >>sys.stderr, t, "/", T
    n = read_int()
    lst = [read_strs() for i in xrange(n)]
    solmy = solve(lst)
    if 0:
        solbrute = brute(lst)
        if solmy != solbrute:
            print "ERR", lst
            print solmy
            print solbrute
            quit()
    print "Case #%d: %s" % (t, solmy)
