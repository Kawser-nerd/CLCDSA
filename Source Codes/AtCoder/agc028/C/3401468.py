#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
AGC028 C
"""

from operator import itemgetter

n = int(input())
abli = []
for i in range(n):
    a, b = map(int, input().split())
    abli.append((a, i, 0))
    abli.append((b, i, 1))

abli.sort(key=itemgetter(0))
tmpans0 = sum(map(itemgetter(0), abli[:n]))
aiset = set([i for x, i, aorb in abli[:n] if not aorb])
biset = set([i for x, i, aorb in abli[:n] if aorb])
flag = bool(set.intersection(aiset, biset))


y, j, arob2 = abli[n]
z, k, arob3 = abli[n+1]

if flag:
    tmpans = tmpans0
else:
    min1 = y-max([x for x, i, aorb in abli[:n] if j != i])
    min2 = z-max([x for x, i, aorb in abli[:n] if j == i])
    tmpans = tmpans0 + min(min1, min2)

leftsum = sum([aa for aa, i, aorb in abli if not aorb])
rightsum = sum([bb for bb, i, aorb in abli if aorb])

print(min(leftsum, rightsum, tmpans))