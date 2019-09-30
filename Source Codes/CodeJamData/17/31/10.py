#!/usr/bin/env python
#-*- coding:utf-8 -*-

import sys, math, random, operator
from string import ascii_lowercase, ascii_uppercase
from fractions import Fraction, gcd
#from decimal import Decimal, getcontext
from itertools import product, permutations, combinations
from Queue import Queue, PriorityQueue
from collections import deque, defaultdict, Counter
#getcontext().prec = 100

MOD = 10**9 + 7
INF = float("+inf")

if sys.subversion[0] == "PyPy":
    import io, atexit
    sys.stdout = io.BytesIO()
    atexit.register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))
    sys.stdin = io.BytesIO(sys.stdin.read())
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

def solve(n, k, rhs):
    assert n == len(rhs)
    rhs.sort(key=lambda (r,h): (-r, -h))
    dp = defaultdict(int)
    for pos in xrange(n):
        r, h = rhs[pos]
        for taken in reversed(xrange(1, pos+1)):
            dp[taken+1] = max(dp[taken+1], dp[taken] + 2*r*h)
        dp[1] = max(dp[1], r**2 + 2*r*h)
    return dp[k] * math.pi


t = read_int()
for j in xrange(t):
    n, k = read_ints()
    rhs = []
    for i in xrange(n):
        rhs.append(read_ints())

    ans = solve(n, k, rhs)
    print "Case #%d: %.10f" % (j+1, ans)
    # epr(j+1, ans)
