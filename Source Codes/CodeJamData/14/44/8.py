#!/usr/bin/env python3

import sys

from itertools import product


def rl(T):
    return list(map(T, raw_input().split()))


def insert(d, s):
    ans = 0
    if len(s) == 0:
        ans = 0
    else:
        c = s[0]
        if c in d:
            ans = insert(d[c], s[1:])
        else:
            nd = dict()
            ans = 1 + insert(nd, s[1:])
            d[c] = nd

    return ans


def solve_single(A):
    root = dict()
    ans = 1
    for s in A:
        ans += insert(root, s)
    #print(A,ans)
    return ans


def solve_config(M, N, A, config):
    ans = 0

    srvs = set(config)
    for srv in srvs:
        ids = [i for i, v in enumerate(config) if v == srv]
        ans += solve_single([A[i] for i in ids])

    return ans


def solve(M, N, A):
    configs = list(product(range(N), repeat=M))

    worst = 0
    count = 0

    visited = dict()
    for config in configs:
        #print(M,N,config)
        c_worst = solve_config(M, N, A, config)
        if c_worst > worst:
            worst = c_worst
            count = 1
        elif c_worst == worst:
            count += 1

    return worst, count


def main():
    sys.setrecursionlimit(100000)
    T, = rl(int)
    for C in range(1, T + 1):
        M, N = rl(int)
        A = []
        for i in range(M):
            A.append(rl(str)[0])
        worst, count = solve(M, N, A)
        print('Case #%d: %d %d' % (C, worst, count))
    pass


main()