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

def n_to_xy(n, ny, nx):
    if n < nx:
        return (n, 0, "d")
    n -= nx
    if n < ny:
        return (nx - 1, n, "l")
    n -= ny
    if n < nx:
        return (nx - 1 - n, ny - 1, "u")
    n -= nx
    return (0, ny - 1 - n, "r")

invdir = dict(l="r", r="l", u="d", d="u")

def move(map, x, y, d1):
    move = None
    if d1 == "d":
        if map[y][x] == 0: move = "l"
        if map[y][x] == 1: move = "r"
    elif d1 == "u":
        if map[y][x] == 0: move = "r"
        if map[y][x] == 1: move = "l"
    elif d1 == "l":
        if map[y][x] == 0: move = "d"
        if map[y][x] == 1: move = "u"
    elif d1 == "r":
        if map[y][x] == 0: move = "u"
        if map[y][x] == 1: move = "d"
    else:
        print "WAT", d1
        quit()
    return movexy(x, y, move) + (move,)

def movexy(x, y, move):
    if move == "l": return (x - 1, y)
    if move == "r": return (x + 1, y)
    if move == "u": return (x, y - 1)
    if move == "d": return (x, y + 1)
    assert 0, move

def is_end(x, y, ny, nx):
    if y < 0 or x < 0:
        return True
    if x >= nx or y >= ny:
        return True

def is_good(ny, nx, map, pairs):
    for i in xrange(0, len(pairs), 2):
        n1 = pairs[i] - 1
        n2 = pairs[i+1] - 1
        x1, y1, d1 = n_to_xy(n1, ny, nx)

        x2, y2, d2 = n_to_xy(n2, ny, nx)
        d2 = invdir[d2]
        x2, y2 = movexy(x2, y2, d2)

        while 1:
            x1, y1, d1 = move(map, x1, y1, d1)
            if is_end(x1, y1, ny, nx):
                if (x1, y1, d1) != (x2, y2, d2):
                    return False
                break
    return True




def tostr(map):
    s = ""
    for y, row in enumerate(map):
        s += "".join("/" if c == 0 else "\\" for c in row)
        s += "\n"
    return s

def solve_brute(ny, nx, pairs):
    for bits in product(range(2), repeat=ny*nx):
        map = []
        for y in xrange(ny):
            map.append([])
            for x in xrange(nx):
                map[y].append(bits[y*nx + x])
        if is_good(ny, nx, map, pairs):
            return tostr(map)
    return "IMPOSSIBLE"

def solve_fast():
    pass

t = read_int()
for t in xrange(1, t + 1):
    ny, nx = read_ints()
    pairs = read_ints()
    epr(t, ny, nx)
    ans_brute = solve_brute(ny, nx, pairs)
    # ans_fast = solve_fast(???)
    # if ans_fast != ans_brute:
    #     print "BAD", ans_brute, ans_fast
    #     quit()
    print "Case #%d:\n%s" % (t, ans_brute.strip())
