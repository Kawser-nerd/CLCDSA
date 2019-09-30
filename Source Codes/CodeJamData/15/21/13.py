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

from Queue import PriorityQueue


def inv(n):
    s = str(n)[::-1].lstrip("0")
    return int(s)


def solve_old(n):
    if n == 1:
        return 1
    q = PriorityQueue()
    q.put((1, -1))
    # print "GO", n
    visited = set()
    while not q.empty():
        step, v = q.get()
        # if n == 19:
        #     print step, v
        v = -v
        from_inc = v + 1
        from_inv = inv(v)
        if from_inc == n or from_inv == n:
            return step + 1
        if from_inv < n and from_inv not in visited:
            q.put((step + 1, -from_inv))
            visited.add(from_inv)
        if from_inc != from_inv:
            if from_inc < n and from_inc not in visited:
                q.put((step + 1, -from_inc))
                visited.add(from_inc)
    raise EOFError()


def solve(n):
    sn = str(n)
    l = len(sn)
    if n <= 9:
        return n
    cur = pow(10, l - 1)
    steps = 0
    if l >= 2:
        steps += 10
    if l >= 3:
        steps += 19
    for xl in xrange(4, l + 1):
        k = xl / 2
        steps += pow(10, k)
        if xl & 1 == 0:
            steps += pow(10, k - 1) - 1
        else:
            steps += pow(10, k) - 1

    if cur == n:
        return steps

    scur = str(cur)

    half = l / 2
    goal_left, goal_right = sn[:half], sn[half:]
    cur_left, cur_right = scur[:half], scur[half:]

    cur_right = int(cur_right)
    goal_right = int(goal_right)
    cur_left = int(cur_left)
    goal_left = int(goal_left)

    if goal_right == 0:
        left = int(str(goal_left - 1)[::-1])
        if goal_left == pow(10, half - 1) + 1:
            # print cur_left, cur_right, "?", goal_left, goal_right
            steps += pow(10, len(sn[half:]))
            return steps
        steps += left
        steps += 1  # swap
        steps += pow(10, len(sn[half:])) - 1
        return steps
    else:
        left = int(str(goal_left)[::-1])
        if left != 1:
            steps += left
            steps += 1  # swap
            right = goal_right - 1
            steps += right
        else:
            steps += goal_right
        return steps


t = read_int()
prev = 0
for i in xrange(t):
    n = read_int()
    # res = solve_old(n)
    # res = solve_old(n)
    # print res, "diff", res - prev
    # prev = res
    # print "Case #%d: %d" % (i + 1, solve(n))
    if 0:
        a = solve(n)
        b = solve_old(n)
        print "#", i, "n=", n, ": (new, old)", a, b, a == b
        if a != b:
            break
    else:
        print "Case #%d: %d" % (i + 1, solve(n))



