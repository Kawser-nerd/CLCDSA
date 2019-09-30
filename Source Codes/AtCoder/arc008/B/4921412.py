# -*- coding: utf-8 -*-

import sys
import copy

input = sys.stdin.readline

# ---------------------------------------------------------

from collections import Counter

N, M = map(int, input().split())
name = input().rstrip()
kit = input().rstrip()

name_cnt = Counter(name)
kit_cnt = Counter(kit)

for key, val in name_cnt.items():
    if kit_cnt[key] == 0:
        print(-1)
        exit()

ans = 0
for key, val in name_cnt.items():
    d = kit_cnt[key]
    ans = max(ans, (val + d - 1) // d)

print(ans)