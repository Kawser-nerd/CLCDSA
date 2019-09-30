#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import array
from bisect import *
from collections import *
import fractions
import heapq 
from itertools import *
import math
import random
import re
import string
import sys

N, W = map(int, input().split())
d = defaultdict(list)
w1 = 0
for n in range(N):
    w, v = map(int, input().split())
    d[w].append(v)
    if n == 0:
        w1 = w

# ??????????????K??????????????????
best_ks = {}
for w in range(w1, w + 4):
    vs = sorted(d[w], reverse=True)
    s = 0
    best_k = [0]
    for v in vs:
        s += v
        best_k.append(s)
    best_ks[w] = best_k

ans = 0
for w1_num in range(len(d[w1])+1):
    for w2_num in range(len(d[w1+1])+1):
        for w3_num in range(len(d[w1+2])+1):
            for w4_num in range(len(d[w1+3])+1):
                weight \
                    = w1_num * w1 \
                    + w2_num * (w1 + 1) \
                    + w3_num * (w1 + 2) \
                    + w4_num * (w1 + 3)
                # print(w1_num, w2_num, w3_num, w4_num, weight)
                if weight > W:
                    continue
                value \
                    = best_ks[w1][w1_num] \
                    + best_ks[w1 + 1][w2_num] \
                    + best_ks[w1 + 2][w3_num] \
                    + best_ks[w1 + 3][w4_num]
                ans = max(ans, value)
print(ans)