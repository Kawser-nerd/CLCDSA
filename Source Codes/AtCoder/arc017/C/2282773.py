# -*- coding: utf-8 -*-
from collections import defaultdict
def inpl(): return list(map(int, input().split()))
N, X = inpl()
W = [int(input()) for _ in range(N)]

A = N//2
B = N-A
C = defaultdict(int)
D = defaultdict(int)

for i in range(2**A):
    C[sum([W[a] * (i>>a&1) for a in range(A)])] += 1
for j in range(2**B):
    D[sum([W[b+A] * (j>>b&1) for b in range(B)])] += 1

ans = 0
for k, v in C.items():
    ans += v*D[X-k]
print(ans)