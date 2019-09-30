#!/usr/bin/env python3
import sys
from functools import reduce
from operator import mul

sys.setrecursionlimit(500000)

N = int(input())
graph = [[] for _ in range(N)]

fdp = [None] * N
gdp = [None] * N

MOD = 10**9 + 7


def f(s, prev):
    if fdp[s] is not None:
        return fdp[s]
    p = reduce(mul, [g(t, s) for t in graph[s] if t != prev], 1)
    fdp[s] = (g(s, prev) + p) % MOD
    return fdp[s]


def g(s, prev):
    if gdp[s] is not None:
        return gdp[s]
    p = reduce(mul, [f(t, s) for t in graph[s] if t != prev], 1)
    gdp[s] = p % MOD
    return gdp[s]


for _ in range(N - 1):
    a, b = (int(x) - 1 for x in input().split())
    graph[a].append(b)
    graph[b].append(a)

print(f(0, -1))