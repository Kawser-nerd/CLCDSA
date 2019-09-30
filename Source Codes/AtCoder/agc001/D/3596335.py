#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc001 D
"""

n, m = map(int, input().split())
ali = list(map(int, input().split()))

if m == 1 and ali[0] == 1:
    print(1)
    print(1)
    print(1)
    exit()

if m == 1:
    print(ali[0])
    print(2)
    print(ali[0]-1, 1)
    exit()

flag = 0
c = []
for a in ali:
    if a % 2 == 1:
        if flag == 0:
            lm = a
            flag += 1
        elif flag == 1:
            rm = a
            flag += 1
        elif flag == 2:
            print('Impossible')
            exit()
    else:
        c.append(a)

if flag == 0:
    lm = c[0]
    del c[0]
    rm = c.pop()

if flag == 1:
    rm = c.pop()

b = [lm+1] + c
d = [lm] + c + [rm]

if rm > 1:
    b.append(rm-1)


print(" ".join(map(str, d)))
print(len(b))
print(" ".join(map(str, b)))