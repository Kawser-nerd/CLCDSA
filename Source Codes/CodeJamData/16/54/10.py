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


def solve_brute():
    return 1

def solve_fast():
    if bad != "1" * L:
        return "SORRY"
    if bad in good:
        return "IMPOSSIBLE"
    # p1 = "?" * L
    # p2 = "01" * (L - 1) + "0"
    # p2 = "10" * (L - 1)
    p1 = "1" * (L - 1)
    p2 = "0?" * L
    if bad == "1" and good == ["0"]:
        p1 = "0"
        p2 = "?"
    assert p1
    assert p2
    assert len(p1) + len(p2) <= 200, (len(p1), len(p2))
    return "%s %s" % (p1, p2)


t = read_int()
for t in xrange(1, t + 1):
    N, L = read_ints()
    good = read_strs()
    for s in good:
        assert len(s) == L
    bad = read_str()
    epr(t, N, L, bad)

    ans_fast = solve_fast()
    if 0:
        ans_brute = solve_brute()
        if ans_fast != ans_brute:
            print "BAD", ans_brute, ans_fast
            quit()
    print "Case #%d: %s" % (t, ans_fast)
