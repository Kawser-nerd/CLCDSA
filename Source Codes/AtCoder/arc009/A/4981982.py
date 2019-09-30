# -*- coding: utf-8 -*-

import sys
import copy

# input = sys.stdin.readline

# ~~~~~~~~~~~~~~~~~~~~~_(??? ? ?)_~~~~~~~~~~~~~~~~~~~~~


N = int(input())

sum = 0

for _ in range(N):
    a, b = map(int, input().split())
    sum += a * b

print(int(sum * 1.05))