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

def recurse(tl, tr, can, n):
    if len(tl) == 4:
        return
    for l in xrange(n):
        if l in tl:
            continue
        good = 0
        for r in can[l]:
            if r in tr:
                continue
            good += 1
            res = recurse(tl + [l], tr + [r], can, n)
            if res:
                return res
        # print "\t" * len(tl), tl, tr, l, r, good
        if good == 0:
            return True

def getcost(m, y, row):
    ans = 0
    for x0, x1 in zip(m[y], row):
        if x0 > x1:
            return -10000
        ans += (x1 - x0)
    return ans

def solve_brute(n, m, can):
    # print "CAN", can
    if not recurse([], [], can, n):
        # print "GOOD"
        return 0

    cur_best = n**2
    srows = list(product(range(2), repeat=n))
    allcases = product(srows, repeat=n)
    allcases = [
        (sum(getcost(m, y, rows[y]) for y in xrange(n)), rows)
        for rows in allcases
    ]
    allcases.sort()
    for cost, rows in allcases:
        if cost < 0:
            continue
        if cost >= cur_best:
            continue
        can = {}
        for y, row in enumerate(rows):
            can[y] = []
            for x, c in enumerate(row):
                if c:
                    can[y].append(x)
        if not recurse([], [], can, n):
            cur_best = min(cur_best, cost)
    return cur_best

def solve_fast(n, m):
    pass

t = read_int()
for t in xrange(1, t + 1):
    n = read_int()
    m = {}
    can = {}
    for y in xrange(n):
        s = read_str()
        can[y] = []
        m[y] = []
        for x, c in enumerate(s):
            m[y].append(int(c))
            if int(c):
                can[y].append(x)
    epr(t, n, m, can)
    ans_brute = solve_brute(n, m, can)
    # ans_fast = solve_fast(n, m)
    # if ans_fast != ans_brute:
    #     print "BAD", ans_brute, ans_fast
    #     quit()
    print "Case #%d: %d" % (t, ans_brute)
