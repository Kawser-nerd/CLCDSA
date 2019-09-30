#!/usr/bin/env python3
from itertools import product


def f(sx, sy):
    global S
    xs = [0, 1, 1, 0, -1, -1, -1, 0, 1]
    ys = [0, 0, 1, 1, 1, 0, -1, -1, -1]
    for dx, dy in zip(xs, ys):
        tx = sx + dx
        ty = sy + dy
        if tx < 0 or H - 1 < tx or ty < 0 or W - 1 < ty:
            continue
        if S[tx][ty] == '.':
            return False
    return True


def g(sx, sy):
    global T
    xs = [0, 1, 1, 0, -1, -1, -1, 0, 1]
    ys = [0, 0, 1, 1, 1, 0, -1, -1, -1]
    for dx, dy in zip(xs, ys):
        tx = sx + dx
        ty = sy + dy
        if tx < 0 or H - 1 < tx or ty < 0 or W - 1 < ty:
            continue
        if T[tx][ty] == '#':
            return True
    return False


H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
T = [['.'] * W for _ in range(H)]
U = [['.'] * W for _ in range(H)]
for sx, sy in product(range(H), range(W)):
    T[sx][sy] = '#' if f(sx, sy) else '.'

for sx, sy in product(range(H), range(W)):
    U[sx][sy] = '#' if g(sx, sy) else '.'

if S != U:
    print('impossible')
    exit()

print('possible')
for i in range(H):
    print(''.join(T[i]))