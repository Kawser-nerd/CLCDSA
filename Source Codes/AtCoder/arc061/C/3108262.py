# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub

sys.setrecursionlimit(10000)


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


def bfs01(g, s):
    d = {}
    for v in g.keys():
        d[v] = sys.maxsize
    d[s] = 0

    if s not in d:
        return d
    q = deque()
    q.append((d[s], s))

    NM = 1 << 30
    while q:
        _, u = q.popleft()
        for v in g[u]:
            if v > NM:
                c = 0
            else:
                c = 1
            alt = c + d[u]
            if d[v] > alt:
                d[v] = alt
                if c == 0:
                    q.appendleft((d[v], v))
                else:
                    q.append((d[v], v))
    return d


@mt
def slv(N, M):

    g = defaultdict(list)
    NM = 30
    for _ in range(M):
        p, q, c = input().split()
        p = int(p)
        q = int(q)
        c = int(c)

        cp = (c << NM) + p
        cq = (c << NM) + q
        g[cp].append(cq)
        g[cq].append(cp)
        g[cp].append(p)
        g[cq].append(q)
        g[p].append((cp))
        g[q].append((cq))

    d = bfs01(g, 1)
    return -1 if N not in d or d[N] == sys.maxsize else d[N]


def main():
    N, M = read_int_n()

    print(slv(N, M))


if __name__ == '__main__':
    main()