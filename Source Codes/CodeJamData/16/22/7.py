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

digits = "1234567890"

def brute(pat1, pat2):
    n = len(pat1)
    ans = None
    min_key = (10**20, 10**20, 10**20)

    for n1 in xrange(1000):
        s1 = str(n1).rjust(n, "0")
        if len(s1) != n:
            continue
        for c, p in zip(s1, pat1):
            if c != p and p != "?":
                break
        else:
            for n2 in xrange(1000):
                s2 = str(n2).rjust(n, "0")
                if len(s2) != n:
                    continue
                for c, p in zip(s2, pat2):
                    if c != p and p != "?":
                        break
                else:
                    key = abs(n1 - n2), n1, n2
                    if key < min_key:
                        min_key = key
                        ans = s1, s2
    s1, s2 = ans
    return s1 + " " + s2

def solve(s1, s2):
    # print s1, s2
    assert len(s1) == len(s2)
    n = len(s1)
    s1 = list(s1)
    s2 = list(s2)
    min_key = (10**20, 10**20, 10**20)
    min_s1 = None
    min_s2 = None
    for i in xrange(n):
        # print i, s1[:i], s2[:i]
        if s1[:i] < s2[:i]:
            t1 = "".join(s1[:i]) + "".join(s1[i:]).replace("?", "9")
            t2 = "".join(s2[:i]) + "".join(s2[i:]).replace("?", "0")
            key = abs(int(t1) - int(t2)), int(t1), int(t2)
            if key < min_key:
                min_key = key
                min_s1 = t1
                min_s2 = t2
            break
        elif s1[:i] > s2[:i]:
            t1 = "".join(s1[:i]) + "".join(s1[i:]).replace("?", "0")
            t2 = "".join(s2[:i]) + "".join(s2[i:]).replace("?", "9")
            key = abs(int(t1) - int(t2)), int(t1), int(t2)
            if key < min_key:
                min_key = key
                min_s1 = t1
                min_s2 = t2
            break

        assert s1[:i] == s2[:i]
        can1 = digits if s1[i] == "?" else s1[i]
        can2 = digits if s2[i] == "?" else s2[i]
        for c1, c2 in product(can1, can2):
            if abs(int(c1) - int(c2)) > 1:
                continue
            if c1 < c2:
                t1 = "".join(s1[:i]) + c1 + "".join(s1[i+1:]).replace("?", "9")
                t2 = "".join(s2[:i]) + c2 + "".join(s2[i+1:]).replace("?", "0")
                key = abs(int(t1) - int(t2)), int(t1), int(t2)
                if key < min_key:
                    min_key = key
                    min_s1 = t1
                    min_s2 = t2
            elif c1 > c2:
                t1 = "".join(s1[:i]) + c1 + "".join(s1[i+1:]).replace("?", "0")
                t2 = "".join(s2[:i]) + c2 + "".join(s2[i+1:]).replace("?", "9")
                key = abs(int(t1) - int(t2)), int(t1), int(t2)
                if key < min_key:
                    min_key = key
                    min_s1 = t1
                    min_s2 = t2
            else:
                assert c1 == c2
                if s1[i] == s2[i] == "?" and c1 > "0":
                    continue
                s1[i] = c1
                s2[i] = c2
    else:
        t1 = "".join(s1)
        t2 = "".join(s2)
        key = abs(int(t1) - int(t2)), int(t1), int(t2)
        if key < min_key:
            min_key = key
            min_s1 = t1
            min_s2 = t2
    return "".join(min_s1) + " " + "".join(min_s2)
    # best_key_by_pos = {}
    # q = Queue()
    # q.put(("", ""))
    # while not q.empty():
    #     c1, c2 = q.get()



t = read_int()
for t in xrange(1, t + 1):
    s1, s2 = read_strs()
    solmy = solve(s1, s2)
    if 0:
        solbrute = brute(s1, s2)
        if solmy != solbrute:
            print "ERR", s1, s2
            print solmy
            print solbrute
            quit()
    print "Case #%d: %s" % (t, solmy)
