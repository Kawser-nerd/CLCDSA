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


def solve_brute(n, k, ps):
    ps.sort()
    # sel = ps[:k/2] + ps[-k/2:]
    ans = -1.0
    for sel in combinations(ps, k):
        probs = defaultdict(float)
        probs[0] = 1.0
        for pcur in sel:
            for cnt, prcnt in probs.copy().items():
                probs[cnt] -= prcnt
                probs[cnt] += prcnt * (1 - pcur)
                probs[cnt + 1] += prcnt * pcur
        # if probs[k/2] > ans:
            # print "SEL", sel
            # print "  /", ps
            # print "res", probs[k/2]
        assert len(sel) == k
        ans = max(ans, probs[k/2])
    return ans

def compute_prob(sel):
    probs = defaultdict(float)
    probs[0] = 1.0
    for pcur in sel:
        for cnt, prcnt in probs.copy().items():
            probs[cnt] -= prcnt
            probs[cnt] += prcnt * (1 - pcur)
            probs[cnt + 1] += prcnt * pcur
    return probs[k/2]

def solve_fast(n, k, ps):
    ps.sort()
    ans = -1.0
    for l in xrange(k + 1):
        r = k - l
        sel = ps[:l] + ps[::-1][:r]
        # assert len(sel) == k, (n, k, len(sel), l, r)
        ans = max(ans, compute_prob(sel))
    return ans

t = read_int()
for t in xrange(1, t + 1):
    n, k = read_ints()
    ps = read_floats()
    epr(t, n, k)
    ans_fast = solve_fast(n, k, ps)
    # ans_brute = solve_brute(n, k, ps)
    # if abs(ans_fast - ans_brute) > 0.00001:
    #     print "BAD", ans_brute, ans_fast
    #     quit()
    print "Case #%d: %.7f" % (t, ans_fast)
