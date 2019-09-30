#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
AGC018 B
"""

from collections import Counter

n, m = map(int, input().split())
alili = [list(map(int, input().split())) for i in range(n)]

cnt = Counter()

for i in range(n):
    cnt[alili[i][0]] += 1

ans = cnt.most_common(1)[0][1]
delset = set()

for j in range(m-1):
    x, tmp = cnt.most_common(1)[0]
    if tmp < ans:
        ans = tmp
    del cnt[x]
    delset.add(x)
    for i in range(n):
        if alili[i][0] == x:
            while alili[i][0] in delset:
                del alili[i][0]
            cnt[alili[i][0]] += 1

print(ans)