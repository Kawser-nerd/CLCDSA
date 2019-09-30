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

def dist(i, j):
    x, y, z = asteroids[i]
    X, Y, Z = asteroids[j]
    return math.sqrt( (X-x)**2 + (Y-y)**2 + (Z-z)**2 )

def solve_brute():
    dists = sorted(dist(i, j) for i, j in combinations(range(N), 2))
    l = 0
    r = len(dists) - 1

    res = dist(0, 1)
    while r >= l:
        mid = (l + r) >> 1
        if good(dists[mid]):
            res = dists[mid]
            r = mid - 1
        else:
            l = mid + 1
    return res

EPS = 1e-9

def good(d):
    tocheck = {0}
    tovisit = set(range(N))
    tovisit.remove(0)
    while tocheck:
        tocheck2 = set()
        for c in tocheck:
            for v in tovisit.copy():
                if dist(c, v) <= d + EPS:
                    tocheck2.add(v)
                    tovisit.remove(v)
                    if v == 1:
                        # print c, "to", v
                        return True
        tocheck = tocheck2
    return False

def solve_fast():
    return solve_brute()


t = read_int()
for t in xrange(1, t + 1):
    N, S = read_ints()
    asteroids = []
    asteroids_speed = []
    for _ in xrange(N):
        v = read_ints()
        asteroids.append(v[:3])
        asteroids_speed.append(v[3:])
    epr(t, N, S)

    ans_fast = solve_fast()
    if 0:
        ans_brute = solve_brute()
        if ans_fast != ans_brute:
            print "BAD", ans_brute, ans_fast
            quit()
    print "Case #%d: %.7f" % (t, ans_fast)
