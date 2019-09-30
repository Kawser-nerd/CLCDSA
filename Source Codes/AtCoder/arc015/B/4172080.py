# -*- coding: utf-8 -*-
#! python3

n = int(input())
ans = [0]*6

for _ in range(n):
    t1, t2 = map(float, input().split())
    if t1 >= 35:
        ans[0] += 1
    if 30 <= t1 <35:
        ans[1] += 1
    if 25 <= t1 <30:
        ans[2] += 1
    if t2 >= 25:
        ans[3] +=1
    if t2 < 0 and t1 >= 0:
        ans[4] += 1
    if t1 < 0:
        ans[5] += 1

print(' '.join(map(str, ans)))