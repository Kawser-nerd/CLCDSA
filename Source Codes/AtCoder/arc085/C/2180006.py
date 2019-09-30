#!/usr/bin/env python3

from sys import stdin
from fractions import gcd	# math.gcd is introduced in python 3.5
from functools import reduce

def lcm(x, y):
    """The least common multiple of x and y."""
    return x * (y // gcd(x, y))

def multiples(t, N):
    """Set of multiples (<= N) of some x in t."""
    return set(i for x in t for i in range(x, N + 1, x))

def value(a, t):
    """The value of the jewels that are labeled a multiple of some x in t."""
    return sum(a[i - 1] for i in multiples(t, len(a)))

def remove(a, t):
    """Break all jewels that are labeled a multiple of some x in t."""
    for i in multiples(t, len(a)):
        a[i - 1] = 0

def tuples(m, N):
    """
    List of tuples over {m,...,N}.
    Each tuple t in the list satisfies that:
        the lcm of t is less than or equal to N, and
        t does not contain a proper multiple of some j in t.
    """
    if m > N: return [()]
    ts = tuples(m + 1, N)
    us = [(m,) + t for t in ts
          if reduce(lcm, t, m) <= N and all(j % m != 0 for j in t)]
    ts.extend(us)
    return ts

def solve(a):
    N = len(a)
    for t in tuples(1, N):
        if value(a, t) < 0: remove(a, t)
    return sum(a)

N = int(stdin.readline())
a = [int(w) for w in stdin.readline().split()]
if len(a) != N: raise
print(solve(a))