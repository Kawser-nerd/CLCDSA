# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

N = int(input())

ans = 1000000000000000

for i in range(100):
    for j in range(100):
        money = i * 15 + j * 100
        tako = i + j * 10
        if tako >= N:
            ans = min(ans, money)


print(ans)