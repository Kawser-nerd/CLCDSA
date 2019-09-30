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

read_str = raw_input
read_strs = lambda: raw_input().split()
read_int = lambda: int(raw_input())
read_ints = lambda: map(int, raw_input().split())
read_float = lambda: float(raw_input())
read_floats = lambda: map(float, raw_input().split())

"---------------------------------------------------------------"



def solve(hs):
    if len(hs) <= 1:
        return 0
    # print hs
    a, b = hs
    if a[1] < b[1]:
        a, b = b, a

    pos1, time1 = a
    pos2, time2 = b
    time_slow = Fraction((360 - pos1) * time1, 360)
    time_fast = Fraction((360 - pos2 + 360) * time2, 360)
    if time_fast <= time_slow:
        return 1
    return 0


t = read_int()
for t in xrange(1, t + 1):
    n = read_int()
    hs = []
    # print n
    for i in xrange(n):
        d, h, m = read_ints()
        # print d, h, m
        for j in xrange(h):
            hs.append((d, m + j))
    res = solve(hs)
    print "Case #%d: %d" % (t, res)
