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

def solve(n, k, u, ps):
    assert n == k
    res = None
    ps = sorted(ps) + [1.0]
    curn = 1
    curp = ps[0]
    epr(u, ps)
    for p in ps[1:]:
        if res is None:
            if u >= (p - curp) * curn:
                u -= (p - curp) * curn
                curp = p
                curn += 1
            else:
                curp += u / curn
                res = [curp] * curn
                res.append(p)
        else:
            res.append(p)
    epr(curp, curn, res)
    epr()
    if not res:
        assert curp == 1.0
        return 1.0
    return reduce(operator.mul, res)

t = read_int()
for j in xrange(t):
    n, k = read_ints()
    u = read_float()
    ps = read_floats()
    ans = solve(n, k, u, ps)
    print "Case #%d: %.8f" % (j+1, ans)
