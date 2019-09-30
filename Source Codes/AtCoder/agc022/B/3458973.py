#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc022 B
"""

n = int(input())


def nagase(n):
    m, r = divmod(n, 8)
    reg = []
    for i in range(m):
        reg.append(i*12+2)
        reg.append(i*12+3)
        reg.append(i*12+4)
        reg.append(i*12+6)
        reg.append(i*12+8)
        reg.append(i*12+9)
        reg.append(i*12+10)
        reg.append(i*12+12)
    if r == 1:
        reg.append(m*12+6)
    elif r == 2:
        reg.append((m)*12+2)
        reg.append((m)*12+4)
    elif r == 3:
        if m == 0:
            reg = [2, 5, 63]
        else:
            reg.append((m)*12+2)
            reg.append((m)*12+4)
            reg.append((m)*12+6)
    elif r == 4:
        if m == 0:
            reg = [2, 5, 20, 63]
        else:
            reg.append((m)*12+2)
            reg.append((m)*12+4)
            reg.append((m)*12+6)
            reg.append((m)*12+12)
    elif r == 5:
        reg.append((m)*12+2)
        reg.append((m)*12+3)
        reg.append((m)*12+4)
        reg.append((m)*12+6)
        reg.append((m)*12+9)
    elif r == 6:
        reg.append((m)*12+2)
        reg.append((m)*12+3)
        reg.append((m)*12+4)
        reg.append((m)*12+6)
        reg.append((m)*12+9)
        reg.append((m)*12+12)
    elif r == 7:
        reg.append((m)*12+2)
        reg.append((m)*12+3)
        reg.append((m)*12+4)
        reg.append((m)*12+6)
        reg.append((m)*12+8)
        reg.append((m)*12+9)
        reg.append((m)*12+10)
    return reg


print(" ".join(map(str, nagase(n))))