# -*- coding: utf-8 -*-
from bisect import bisect, bisect_left
def inpl(): return list(map(int, input().split()))
N, X = inpl()
W = [int(input()) for _ in range(N)]

A = N//2
B = N-A
C = []
D = []
for i in range(2**A):
    C.append(sum([W[a] * (i>>a&1) for a in range(A)]))
for j in range(2**B):
    D.append(sum([W[b+A] * (j>>b&1) for b in range(B)]))

ans = 0
C = sorted(C)
D = sorted(D)
for c in C[:bisect(C, X)]:
    ans += bisect(D, X-c) - bisect_left(D, X-c)
print(ans)