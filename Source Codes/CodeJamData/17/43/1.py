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

def DFS(v, visited, graph):
    "Depth-first search through graph, appending current node when returning"
    if visited[v]:
        return []
    visited[v] = True
    output = []
    for w in graph[v]:
        output += DFS(w, visited, graph)
    output.append(v)
    return output

def BuildComponents(v, C, visited, reverseGraph):
    "Build components from reverseGraph"
    if visited[v]:
        return C
    visited[v] = True
    if -v in C:
        raise Exception()
    if v not in C:
        C[v] = True
    for w in reverseGraph[v]:
        BuildComponents(w, C, visited, reverseGraph)
    return C

def TwoSAT(Q, n):
    """Calculate 2SAT for query Q with n variables.
    Returns None if no solution, else an object with variable index as key and
    boolean as value."""
    graph = []
    reverseGraph = []
    for i in range((n+1)*2):
        graph.append([])
        reverseGraph.append([])
    for (a, b) in Q:
        graph[-a].append(b)
        graph[-b].append(a)
        reverseGraph[a].append(-b)
        reverseGraph[b].append(-a)
    visited = [False] * ((n+1)*2)
    order = []
    for i in range(n):
        order += DFS(i+1, visited, graph)
        order += DFS(-(i+1), visited, graph)
    order = order[::-1]
    visited = [False] * ((n+1)*2)
    components = []
    try:
        for v in order:
            components.append(BuildComponents(v, {}, visited, reverseGraph))
    except:
        return
    values = {}
    while len(values) < n:
        c = components.pop()
        for p in c:
            if abs(p) not in values:
                values[abs(p)] = abs(p) == p
    return values

"---------------------------------------------------------------"

# \ xx
M1 = {
    (0, -1): (-1, 0),
    (0, 1): (1, 0),
    (-1, 0): (0, -1),
    (1, 0): (0, 1),
}
# /
M2 = {
    (0, -1): (1, 0),
    (0, 1): (-1, 0),
    (-1, 0): (0, 1),
    (1, 0): (0, -1),
}

def go(y, x, dir, beamer, do_add=False):
    while 1:
        y += dir[0]
        x += dir[1]

        if not (0 <= y < sy):
            return True
        if not (0 <= x < sx):
            return True

        c = grid[y][x]
        # print "LOG" ,y, x, c, dir
        if c == '#':
            return True
        elif c in '-|':
            epr("   beamer", beamer, "kill", y, x)
            return False
        elif c == '.':
            if do_add:
                pos_to_beamer[y,x].add(beamer)
            # return go(y, x, dir, beamer, do_add)
        elif c == '\\':
            dir = M1[dir]
            # return go(y, x, dir, beamer, do_add)
        elif c == '/':
            dir = M2[dir]
            # return go(y, x, dir, beamer, do_add)
        else:
            assert 0

def solve(sy, sx, grid):
    pos2var = {}
    var2pos = {}
    vari = 1

    q = []
    for x in xrange(sx):
        for y in xrange(sy):
            if grid[y][x] == '.':
                pos_to_beamer[y,x]
            if grid[y][x] in '-|':
                if (y, x) not in pos2var:
                    v = pos2var[y,x] = vari
                    var2pos[vari] = y,x
                    vari += 1

                hor = [
                    go(y, x, (0, -1), (y, x, 0)),
                    go(y, x, (0, 1), (y, x, 0))
                ]
                ver = [
                    go(y, x, (-1, 0), (y, x, 1)),
                    go(y, x, (1, 0), (y, x, 1))
                ]
                can_hor = hor[0] and hor[1]
                can_ver = ver[0] and ver[1]
                epr("  ", y, x, can_hor, can_ver)
                if not (can_hor or can_ver):
                    return "IMPOSSIBLE"
                if can_hor:
                    go(y, x, (0, -1), (y, x, 0), True)
                    go(y, x, (0, 1), (y, x, 0), True)
                if can_ver:
                    go(y, x, (-1, 0), (y, x, 1), True)
                    go(y, x, (1, 0), (y, x, 1), True)
                if not can_hor:
                    q.append((v, v))
                if not can_ver:
                    q.append((-v, -v))

    # clean
    for pos, bs in pos_to_beamer.items():
        clause = []
        for y, x, val in bs:
            if (y, x, val ^ 1) in bs:
                break
            v = pos2var[y,x]
            if val == 0:
                clause.append(-v)
            else:
                clause.append(v)
        else:
            if not clause:
                return "IMPOSSIBLE"
            if len(clause) == 1:
                clause *= 2
            q.append(tuple(clause))

    res = TwoSAT(q, vari-1)
    epr("sol", res)
    if not res:
        return "IMPOSSIBLE"

    for v, val in res.items():
        y, x = var2pos[v]
        grid[y][x] = '|' if val else '-'
    return "POSSIBLE\n" + "\n".join("".join(row) for row in grid)

epr = lambda *a: 1
t = read_int()
for j in xrange(t):
    sy, sx = read_ints()
    grid = [list(read_str()) for _ in xrange(sy)]

    pos_to_beamer = defaultdict(set)

    ans = solve(sy, sx, grid)
    print "Case #%d: %s" % (j+1, ans)
    epr()
