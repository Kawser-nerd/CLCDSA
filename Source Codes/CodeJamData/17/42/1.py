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
from copy import deepcopy
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

def good(by_pos, h):
    by_pos = deepcopy(by_pos)
    tocut = []
    for pos in sorted(by_pos, reverse=True):
        if len(by_pos[pos]) > h:
            tocut.append(pos)
    if not tocut:
        return 0

    ans = 0
    for dst in xrange(1, 2000):
        while len(by_pos[dst]) < h:
            src = tocut[-1]
            if src <= dst:
                return
            by_pos[dst].append(by_pos[src].pop())
            ans += 1
            if len(by_pos[src]) <= h:
                tocut.pop()
                if not tocut:
                    return ans
    return ans

def solve(n, c, by_pos, by_id):
    max_h = max(len(v) for v in by_pos.values())
    res = max_h, 0
    l = max(by_id.values())
    r = max(l, max_h)
    while r >= l:
        mid = (l + r) / 2
        sub = good(by_pos, mid)
        if sub is not None:
            res = mid, sub
            r = mid - 1
        else:
            l = mid + 1
    return res

t = read_int()
for j in xrange(t):
    cache = {}
    n, c, m = read_ints()
    by_pos = defaultdict(list)
    by_id = defaultdict(int)
    for i in xrange(m):
        pos, id = read_ints()
        by_pos[pos].append(id)
        by_id[id] += 1
    ans = solve(n, c, by_pos, by_id)
    print "Case #%d: %s %s" % (j+1, ans[0], ans[1])
