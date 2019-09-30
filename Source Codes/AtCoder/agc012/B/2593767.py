#!/usr/bin/env python3

import sys, math, copy
# import fractions, itertools
# import numpy as np
# import scipy

HUGE = 2147483647
HUGEL = 9223372036854775807
ABC = "abcdefghijklmnopqrstuvwxyz"
MAX = 100001

dp = [0 for i in range(MAX)]
color = [0 for i in range(MAX)]
e = [[] for i in range(MAX)]

def paint(v, d, c):
    if not color[v]:
        color[v] = c
    if dp[v] >= d or d == 0:
        return
    dp[v] = d
    for u in e[v]:
        paint(u, d - 1, c)

def main():
    n, m = map(int, input().split())
    for i in range(m):
        a, b = map(int, input().split())
        e[a].append(b)
        e[b].append(a)
    q = int(input())
    vq, dq, cq = [], [], []
    for i in range(q):
        v, d, c = map(int, input().split())
        vq.append(v)
        dq.append(d)
        cq.append(c)
    assert len(vq) == len(dq) == len(cq) == q

    for i in reversed(range(q)):
        paint(vq[i], dq[i], cq[i])
    for i in range(n):
        print(color[i + 1])


main()