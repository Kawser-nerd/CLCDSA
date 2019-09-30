#!/usr/bin/env python3
from datetime import datetime, timedelta
N = int(input())
dates = [list(map(int, input().split('/'))) for _ in range(N)]
dates.sort()

pv = datetime(2012, 1, 1)
dp = [(i + 1) % 7 < 2 for i in range(366)]
for m, d in dates:
    cur = datetime(2012, m, d)
    days = (cur - pv).days
    for i in range(days, 366):
        if dp[i]:
            continue
        dp[i] = True
        break

s = ''.join(['01'[ok] for ok in dp])
print(max(map(len, s.split('0'))))