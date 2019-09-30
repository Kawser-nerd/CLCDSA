# -*- coding: utf-8 -*-
from sys import setrecursionlimit
setrecursionlimit(10000000)

N = int(input())
C = [[] for _ in range(N+1)]

for i in range(1, N):
    C[int(input())-1].append(i)

def cal(x):
    if len(C[x]) == 0:
        return 0
    else:
        D = sorted([cal(a) for a in C[x]], reverse=True)
        res = 0
        for i, d in enumerate(D, start=1):
            res = max(res, i+d)
        return res

print(cal(0))