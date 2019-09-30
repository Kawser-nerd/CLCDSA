#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc 003
"""

from operator import itemgetter

n = int(input())
ali = [int(input()) for i in range(n)]
sortedali = sorted(enumerate(ali), key=itemgetter(1))

ansdouble = 0
for (i, (j, _)) in enumerate(sortedali):
    if (i-j) % 2 != 0:
        ansdouble += 1

print(ansdouble//2)