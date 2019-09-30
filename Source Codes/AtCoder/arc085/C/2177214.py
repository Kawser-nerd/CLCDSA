#!/usr/bin/env python3

from sys import stdin
from fractions import gcd	# math.gcd is introduced in python 3.5
from functools import reduce

def lcm(x, y):
    """The least common multiple of x and y."""
    return x * (y // gcd(x, y))

def flatten(ls):
    """Flatten a list of lists."""
    return [x for l in ls for x in l]


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
    [[m'-tuples over {1,2,3,...,N}] for 0 <= m' <= m].
    The lcm of the m-tuple is less than or equal to N.
    Each m-tuple does not contain a multiple of some j in the tuple.
    """
    if m == 0: return [[()]]
    ts = tuples(m - 1, N)
    if ts[-1] == []: return ts

    ls = []
    for t in ts[-1]:
        lc = reduce(lcm, t) if len(t) > 0 else 1
        mi = min(t)         if len(t) > 0 else N + 1
        for i in range(mi - 1, 0, -1):
            if lcm(lc, i) > N: continue
            if any(j % i == 0 for j in t): continue
            ls.append((i,) + t)  # smaller label first
    ts.append(ls)
    return ts

def solve(a):
    N = len(a)
    tl = flatten(tuples(N, N))
    # break jewels with larger labels first.
    tl.sort(key=lambda t: [-x for x in t])
    for t in tl:
        if value(a, t) < 0: remove(a, t)
    return sum(a)

N = int(stdin.readline())
a = [int(w) for w in stdin.readline().split()]
if len(a) != N: raise
print(solve(a))