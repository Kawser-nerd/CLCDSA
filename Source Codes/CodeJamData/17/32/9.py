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

def besttake(costs, free):
    res = 0
    for cs, f in zip(costs, free):
        for x in sorted(cs):
            if x <= f:
                f -= x
                res += 2
    return res

def solve(ints):
    free = [720, 720]
    prev = None
    prevint = None
    starter = None
    ender = None
    costs = [[], []]
    nchanges = 0
    cost_start = None
    cost_end = None
    ints.sort()
    for (l, r), who in ints:
        free[who] -= r - l
        if prev is None:
            starter = who
            cost_start = l
        elif prev == who:
            costs[who].append(l - prevint[1])
            nchanges += 2
        else:
            nchanges += 1
        prevint = l, r
        prev = who
    ender = prev
    cost_end = 720*2 - prevint[1]
    epr("free", free, "starter", starter, "ender", ender, "cost_start", cost_start, "cost_end", cost_end, "costs", costs, "nchanges", nchanges)

    if starter == ender:
        nchanges += 2
        costs[starter].append( cost_start + cost_end )
    else:
        nchanges += 1

    # change start + end
    ans = nchanges - besttake(costs, (free[0], free[1]))
    # if free[starter] >= cost_start:
    #     free2 = free[::]
    #     free2[starter] -= cost_start
    #     ans = min(ans, nchanges - 1 - besttake(costs, free2))
    # if free[ender] >= cost_end:
    #     free2 = free[::]
    #     free2[ender] -= cost_end
    #     ans = min(ans, nchanges - 1 - besttake(costs, free2))
    # if free[starter] >= cost_start and free[ender] >= cost_end:
    #     free2 = free[::]
    #     free2[starter] -= cost_start
    #     free2[ender] -= cost_end
    #     ans = min(ans, nchanges - 2 - besttake(costs, free2))
    return ans



t = read_int()
for j in xrange(t):
    n1, n2 = read_ints()
    ints = [(read_ints(), 0) for _ in xrange(n1)]
    ints += [(read_ints(), 1) for _ in xrange(n2)]
    ans = solve(ints)
    print "Case #%d: %d" % (j+1, ans)
