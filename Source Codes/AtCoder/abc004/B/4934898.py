# -*- coding: utf-8 -*-

e = [[i for i in input().split()] for i in range(4)]

new = [e[3], e[2], e[1], e[0]]

for i in new:
    for y in reversed(i):
        print(y, end=' ')
    print()