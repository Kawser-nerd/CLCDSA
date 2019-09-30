# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

from itertools import product
from itertools import combinations

N = int(input())
S = input()

ABXY = "ABXY"

strs = []
for x in product(ABXY, repeat=2):
    s = ''.join(x)
    strs.append(s)

ans = 1e20

for x in strs:
    for y in strs:
        cnt = i = 0
        while i < N:
            cnt += 1
            if S[i: i + 2] == x or S[i: i + 2] == y:
                i += 2
            else:
                i += 1
        ans = min(ans, cnt)


print(ans)