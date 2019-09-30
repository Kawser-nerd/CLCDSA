#!/usr/bin/env python3
import copy
h, w = map(int, input().split())
f = [ list(input()) for _ in range(h) ]
a = copy.deepcopy(f)
b = copy.deepcopy(f)
a[0] = '#' * w
for y in range(1, h - 1):
    for x in range(w):
        [a, b][x % 2][y][x] = '#'
b[h - 1] = '#' * w
print(*map(''.join, a), sep='\n')
print()
print(*map(''.join, b), sep='\n')