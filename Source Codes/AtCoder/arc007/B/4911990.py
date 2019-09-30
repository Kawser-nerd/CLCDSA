# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

N, M = map(int, input().rstrip().split())

disk = [int(input()) for _ in range(M)]

ans = [0] * (N + 1)
for i in range(N + 1):
    ans[i] = i

for x in disk:
    pos = 0
    for i in range(N + 1):
        if ans[i] == x:
            pos = i

    ans[0], ans[pos] = ans[pos], ans[0]

for i in range(1, N + 1):
    print(ans[i])