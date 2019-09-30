# -*- coding: utf-8 -*-
from bisect import bisect, bisect_left
def inpl(): return list(map(int, input().split()))
N, L, T = inpl()

Fants = []
Bants = []
A = [[0, 0] for _ in range(N)]
P = [-1]*N

for i in range(N):
    x, w = inpl()
    A[i] = (x, w)
    if w == 1:
        Fants.append(x)
        P[i] = (x+T)%L
    else:
        Bants.append(x)
        P[i] = (x-T)%L

B = Bants + [b+L for b in Bants] + [b+2*L for b in Bants]
F = [f-2*L for f in Fants] + [f-L for f in Fants] + Fants
d, m = divmod(T, L)
ans = [-1]*N

for i, (x, w) in enumerate(A):
    if w == 1: #forward
        j = i + 2*d*len(Bants) + (bisect(B, x+2*m) - bisect(B, x))
        ans[j%N] = P[i]
    else:
        j = i - 2*d*len(Fants) - (bisect_left(F, x) - bisect_left(F, x-2*m))
        ans[j%N] = P[i]    

print(*ans, sep="\n")