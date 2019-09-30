# -*- coding: utf-8 -*-

import sys
import copy

sys.setrecursionlimit(1000000)

# input = sys.stdin.readline

# ~~~~~~~~~~~~~~~~~~~~~_(??? ? ?)_~~~~~~~~~~~~~~~~~~~~~



b = input().rstrip().split()

N = int(input())

a = [input().rstrip() for _ in range(N)]


def f(s):
    a = [None] * len(s)
    for i, c in enumerate(s):
        k = b.index(c)
        a[i] = str(k)
    return int(''.join(a))


for ans in sorted(a, key=lambda x: f(x)):
    print(ans)