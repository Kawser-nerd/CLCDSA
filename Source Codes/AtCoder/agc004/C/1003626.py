#!/usr/bin/env python
# -*- coding:utf-8 -*-

H, W = map(int, input().split())
blue = [[0] * W for _ in range(H)]
red = [[0] * W for _ in range(H)]

for x in range(W):
    blue[0][x] = 1
    red[-1][x] = 1

for y in range(H-1):
    for x in range(0, W, 2):
        blue[y][x] = 1
        if x + 1 < W:
            red[y+1][x+1] = 1

# for y in range(H):
#     print(blue[y])
# print()
# for y in range(H):
#     print(red[y])

m = [input() for _ in range(H)]

for color in [red, blue]:
    for y in range(H):
        for x in range(W):
            if m[y][x] == '#':
                print('#', end='')
            elif color[y][x] == 1:
                print('#', end='')
            else:
                print(".", end='')
        print()
    print()