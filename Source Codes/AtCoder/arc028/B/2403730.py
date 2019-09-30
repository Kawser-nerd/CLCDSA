# -*- coding: utf-8 -*-
from heapq import heapify, heappushpop
def inpl(): return map(int, input().split())
N, K = inpl()
X = list(inpl())

Q = [(-x, i+1) for i, x in enumerate(X[:K])]

heapify(Q)

for i in range(K, N):
    print(Q[0][1])
    _ = heappushpop(Q, (-X[i], i+1))

print(Q[0][1])