#!/usr/bin/env python3
N = int(input())
color = [int(input()) for _ in range(N)]

s = sum(color)
if s == 0 or s == N:
    print(-1)
    exit()

li = [[0, 1][color[i - 2] == color[i - 1] == color[i]] for i in range(N)]
s = max(map(len, (''.join(map(str, li)) * 2).split('0')))
print((s + 1) // 2 + 1)