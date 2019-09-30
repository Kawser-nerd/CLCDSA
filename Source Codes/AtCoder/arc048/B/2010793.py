# -*- coding: utf-8 -*-
from itertools import accumulate
def inpl(): return tuple(map(int, input().split()))

N = int(input())
S = [0 for _ in range(10**5 + 1)]
P = [[0]*3 for _ in range(10**5+1)]
A = []

for _ in range(N):
    R, H = inpl()
    P[R][H-1] += 1
    S[R] += 1
    A.append([R, H])
S = list(accumulate(S))

for R, H in A:
    w = S[R-1] + P[R][H%3]
    d = P[R][H-1] - 1
    l = N - w - d - 1
    
    print("{} {} {}".format(w, l, d))