#!/usr/bin/env python3
from math import ceil
N, M = map(int, input().split())
name = input()
kit = input()

unit = {}
for c in kit:
    if c in unit:
        unit[c] += 1
    else:
        unit[c] = 1

need = {}
for c in name:
    if c in need:
        need[c] += 1
    else:
        need[c] = 1

ans = 0
for k, v in need.items():
    if k not in unit:
        ans = -1
        break
    ans = max([ans, ceil(v / unit[k])])

print(ans)