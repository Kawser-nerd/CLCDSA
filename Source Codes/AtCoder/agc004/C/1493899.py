#!/usr/bin/env python3
import copy
h, w = map(int, input().split())
f = [ list(input()) for _ in range(h) ]
a = copy.deepcopy(f)
b = copy.deepcopy(f)
for y in range(h):
    for x in range(w):
        if y == 0:
            a[y][x] = '#'
        elif y == h - 1:
            b[y][x] = '#'
        else:
            [a, b][x % 2][y][x] = '#'
print(*map(''.join, a), sep='\n')
print()
print(*map(''.join, b), sep='\n')