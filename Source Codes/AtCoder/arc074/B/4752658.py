# -*- coding: utf-8 -*-
import heapq

n = int(input())
al = list(map(int, input().split()))
q = al[:n]
heapq.heapify(q)

s = sum(al[:n])
ll = [s]
for i in range(n,2*n):
    a = al[i]
    s += a
    a = heapq.heappushpop(q, a)
    s -= a
    ll.append(s)

s = 0
q = []
heapq.heapify(q)
for i in range(2*n, 3*n):
    s -= al[i]
    heapq.heappush(q, -al[i])

rl = [-s]
for i in range(2*n-1,n-1,-1):
    a = al[i]
    s += -a
    a = heapq.heappushpop(q, -a)
    s -= a
    rl.append(-s)
rl.reverse()

res = ll[0]-rl[0]
for i in range(1,n+1):
    res = max(res, ll[i]-rl[i])

print(res)