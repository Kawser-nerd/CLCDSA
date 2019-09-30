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

words = "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
first = dict(
    Z="ZERO",
    W="TWO",
    U="FOUR",
    X="SIX",
    G="EIGHT",
)
second = dict(
    O="ONE",
    T="THREE",
    F="FIVE",
    S="SEVEN",
)
third = dict(
    N="NINE"
)

word_to_digit = {w: words.index(w) for w in words}

def subword(cnt, w):
    for c in w:
        cnt[c] -= 1
        assert cnt[c] >= 0

def solve(s):
    cnt = Counter(s)
    ans = ""
    for pool in (first, second, third):
        for c, w in pool.items():
            while cnt[c] > 0:
                subword(cnt, w)
                ans += str(word_to_digit[w])
    return "".join(sorted(ans))



t = read_int()
for t in xrange(1, t + 1):
    s = read_str()
    print "Case #%d: %s" % (t, solve(s))
