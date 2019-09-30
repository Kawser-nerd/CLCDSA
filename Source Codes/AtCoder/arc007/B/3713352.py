# -*- coding: utf-8 -*-
from itertools import product
def inpl(): return list(map(int, input().split()))
N, M = inpl()
where = list(range(0, N+1))
now = 0

for _ in range(M):
    disk = int(input())
    where[disk], where[now] = where[now], where[disk]
    now = disk

answer = [-1]*(N+1)

for i in range(N+1):
    answer[where[i]] = i
print(*answer[1:], sep="\n")