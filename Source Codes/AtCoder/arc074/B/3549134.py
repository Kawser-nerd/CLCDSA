# -*- coding: utf-8 -*-
from heapq import heappush,heappushpop,heapify

n = int(input())
a = [int(x) for x in input().split()]

q = []
s = 0
for i in range(n):
    heappush(q, a[i])
    s += a[i]
left = [s]
for k in range(n):
    x = heappushpop(q, a[n+k])
    s = s - x + a[n+k]
    left.append(s)

q = []
s = 0
for i in range(n):
    heappush(q, -1*a[3*n-1-i])
    s += a[3*n-1-i]
right = [0 for _ in range(n+1)]
right[n] = s
for k in range(n):
    x = heappushpop(q, -1*a[2*n-1-k])
    s = s - (-1*x) + a[2*n-1-k]
    right[n-1-k] = s

m = None
for k in range(n+1):
    if m is None:
        m = left[k] - right[k]
    else:
        m = max(m, left[k]-right[k])

print(m)