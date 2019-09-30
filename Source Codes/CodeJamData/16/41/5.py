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

c_to_lr = dict(s="ps", r="rs", p="pr")

class Node(object):
    def __init__(self, c, h):
        self.c = c
        self.h = h
        self.l = None
        self.r = None
        if h > 0:
            l, r = c_to_lr[c]
            self.l = Node(l, h - 1)
            self.r = Node(r, h - 1)

    def collapse(self):
        if self.h == 0:
            return
        self.l.collapse()
        self.r.collapse()
        if self.l.c > self.r.c:
            self.l, self.r = self.r, self.l
        self.c = self.l.c + self.r.c

def solve(n, cr, cp, cs):
    words = []
    for c in "prs":
        w = Node(c, n)
        w.collapse()
        s = w.c
        #print s, [s.count(c) for c in "prs"], cp, cr, cs
        if s.count("p") != cp:
            continue
        if s.count("r") != cr:
            continue
        if s.count("s") != cs:
            continue
        words.append(s)
    return min(words) if words else "IMPOSSIBLE"

t = read_int()
for t in xrange(1, t + 1):
    n, r, p, s = read_ints()
    print "Case #%d: %s" % (t, solve(n, r, p, s).upper())
