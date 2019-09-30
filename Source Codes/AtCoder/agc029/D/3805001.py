# coding:utf-8

import sys


input = sys.stdin.readline


def inpl(): return list(map(int, input().split()))


H, W, N = inpl()
L = [W] * H

# ?x??????x??????????????
for i in range(N):
    x, y = inpl()
    x -= 1
    y -= 1
    L[x] = min(L[x], y)

k = 0  # y??????????
for x in range(1, H):
    if L[x] <= k:
        print(x)
        break
    if L[x] != k + 1:
        k += 1
else:
    print(H)