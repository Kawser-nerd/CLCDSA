# -*- coding: utf-8 -*-

import sys
import copy

sys.setrecursionlimit(1000000)

# input = sys.stdin.readline

# ~~~~~~~~~~~~~~~~~~~~~_(??? ? ?)_~~~~~~~~~~~~~~~~~~~~~

N = int(input())

a = [0] * N
b = [0] * N

for i in range(N):
    a[i], b[i] = map(int, input().split())

sum = 0
for i in range(N):
    sum += a[i] * b[i]

print(int(sum * 1.05))