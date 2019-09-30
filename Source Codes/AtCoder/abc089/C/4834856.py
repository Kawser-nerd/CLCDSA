# -*- coding: utf-8 -*-

import itertools

n = int(input())
s = [[] for _ in range(n)]
for i in range(n):
    s[i] = list(input())

delete = []

for i in range(n):
    if s[i][0] == "M" or s[i][0] == "A" or s[i][0] == "R" or s[i][0] == "C" or s[i][0] == "H":
        pass
    else:
        delete.append(i)

diff = 0
for i in range(len(delete)):
    del s[delete[i] - diff]
    diff += 1

cand = [0,0,0,0,0]
for i in range(len(s)):
    if s[i][0] == "M":
        cand[0] += 1
    if s[i][0] == "A":
        cand[1] += 1
    if s[i][0] == "R":
        cand[2] += 1
    if s[i][0] == "C":
        cand[3] += 1
    if s[i][0] == "H":
        cand[4] += 1

ans = 0

for i in range(5):
    for j in range(5):
        if i == j:
            break
        for k in range(5):
            if i == k:
                break
            if j == k:
                break
            ans += int(cand[i] * cand[j] * cand[k])

print(ans)