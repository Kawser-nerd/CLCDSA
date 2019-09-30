#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
AGC021 B
"""

import math
from collections import defaultdict

n = int(input())
ps = [tuple(map(int, input().split())) for i in range(n)]


def dist(rad, p):
    radtmp = 2*math.pi*rad/maxcut
    return -p[0]*math.cos(radtmp)-p[1]*math.sin(radtmp)


def closest(rad):
    tmp = dist(rad, ps[0])
    itmp = 0
    for i, pp in enumerate(ps):
        tmp2 = dist(rad, pp)
        if tmp2 < tmp:
            itmp = i
            tmp = tmp2
    return itmp


maxcut = 2**20


binary = defaultdict(int)
binary[0] = closest(0)
binary[maxcut] = binary[0]
binary[maxcut//2] = closest(maxcut//2)
binary[maxcut//4] = closest(maxcut//4)
binary[3*maxcut//4] = closest(3*maxcut//4)


def fillbinary(ll, rr):
    if binary[ll] != binary[rr] and rr-ll != 1:
        mm = (ll+rr)//2
        binary[mm] = closest(mm)
        fillbinary(ll, mm)
        fillbinary(mm, rr)


fillbinary(0, maxcut//4)
fillbinary(maxcut//4, maxcut//2)
fillbinary(maxcut//2, 3*maxcut//4)
fillbinary(3*maxcut//4, maxcut)


binkeys = sorted(binary.keys())
ansli = [0]*n
beforekey = 0
for i in binkeys:
    ansli[binary[i]] += i-beforekey
    beforekey = i


for i in range(n):
    print(ansli[i]/maxcut)