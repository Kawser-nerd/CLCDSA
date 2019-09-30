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


def large_half(x):
    return x / 2 + (x & 1)


def check(r, c, free, odd):
    MAP = defaultdict(lambda: "x")
    for y in xrange(1, r - 1):
        for x in xrange(1, c - 1):
            if (x + y) & 1 == odd and free > 0:
                MAP[x, y] = " "
                free -= 1
                #print "ASD", x, y
    y = 0
    for x in xrange(1, c - 1):
        if (x + y) & 1 == odd and free > 0:
            MAP[x, y] = " "
            free -= 1
            #print "QWE1", x, y
    y = r - 1
    for x in xrange(1, c - 1):
        if (x + y) & 1 == odd and free > 0:
            MAP[x, y] = " "
            free -= 1
            #print "QWE2", x, y
    x = 0
    for y in xrange(1, r - 1):
        if (x + y) & 1 == odd and free > 0:
            MAP[x, y] = " "
            free -= 1
            #print "QWE3", x, y
    x = c - 1
    for y in xrange(1, r - 1):
        if (x + y) & 1 == odd and free > 0:
            MAP[x, y] = " "
            free -= 1
            #print "QWE", x, y
    for x, y in [(0, 0), (c - 1, 0), (0, r - 1), (c - 1, r - 1)]:
        if (x + y) & 1 == odd and free > 0:
            MAP[x, y] = " "
            free -= 1
            #print "QWE4", x, y
    # for x, y in [(0, 0), (0, c - 1), (r - 1, 0), (r - 1, c - 1)]:
    #     if free > 0:
    #         MAP[x, y] = " "
    #         free -= 1
    assert free == 0
    unhap = 0
    for y in xrange(r):
        for x in xrange(c - 1):
            if MAP[x, y] == "x" and MAP[x + 1, y] == "x":
                unhap += 1
    for x in xrange(c):
        for y in xrange(r - 1):
            if MAP[x, y] == "x" and MAP[x, y + 1] == "x":
                unhap += 1
    # print "CHECK odd %d unhap %d" % (odd, unhap)
    # for y in xrange(r):
    #     for x in xrange(c):
    #         print MAP[x, y],
    #     print
    # print "---"
    return unhap


def solve(r, c, n):
    if r > c:
        r, c = c, r
    area = r * c
    half = large_half(area)
    if n <= half:
        return 0
    if n == area:
        return (c - 1) * r + (r - 1) * c

    if r == 1:
        if c & 1:
            n -= large_half(c)
            return n * 2
        else:
            n -= c / 2
            if n == 0:
                return 0
            elif n == 1:
                return 1
            else:
                return 1 + (n - 1) * 2

    free = area - n
    assert free < area / 2
    # print "HAVING FREE", free
    unhap1 = check(r, c, free, 0)
    unhap2 = check(r, c, free, 1)
    # print "SOLVE", unhap1, unhap2
    return min(unhap1, unhap2)


def solve_brute(r, c, n):
    if r > c:
        r, c = c, r
    ans = 999999
    for xs in product(range(2), repeat=r * c):
        if sum(xs) != n:
            continue
        MAP = defaultdict(lambda: " ")
        i = 0
        for y in xrange(r):
            for x in xrange(c):
                if xs[i]:
                    MAP[x, y] = "x"
                i += 1
        unhap = 0
        for y in xrange(r):
            for x in xrange(c - 1):
                if MAP[x, y] == "x" and MAP[x + 1, y] == "x":
                    unhap += 1
        for x in xrange(c):
            for y in xrange(r - 1):
                if MAP[x, y] == "x" and MAP[x, y + 1] == "x":
                    unhap += 1
        ans = min(ans, unhap)
    # for xs in product(range(2), repeat=r * c):
    #     if sum(xs) != n:
    #         continue
    #     MAP = defaultdict(lambda: " ")
    #     i = 0
    #     for y in xrange(r):
    #         for x in xrange(c):
    #             if xs[i]:
    #                 MAP[x, y] = "x"
    #             i += 1
    #     unhap = 0
    #     for y in xrange(r):
    #         for x in xrange(c - 1):
    #             if MAP[x, y] == "x" and MAP[x + 1, y] == "x":
    #                 unhap += 1
    #     for x in xrange(c):
    #         for y in xrange(r - 1):
    #             if MAP[x, y] == "x" and MAP[x, y + 1] == "x":
    #                 unhap += 1
    #     if ans == unhap:
    #         print "SOLVE BRUTE"
    #         for y in xrange(r):
    #             for x in xrange(c):
    #                 print MAP[x, y],
    #             print
    #         print "---"
    #         return ans
    return ans


t = read_int()
for i in xrange(1, t + 1):
    r, c, n = read_ints()
    if 0:
        print "Case #%d: %d" % (i, solve(r, c, n))
    else:
        a = solve(r, c, n)
        b = solve_brute(r, c, n)
        print "case", i, ":", r, c, n, ":", a, b, a == b
        if a != b:
            break
