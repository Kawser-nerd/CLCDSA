# -*- coding: utf-8 -*-
s = list(input())
n = len(s)
res = 10**6

for k in range(n-1):
    if s[k]!=s[k+1]:
        res = min(res, max(k+1, n-k-1))

if res==10**6:
    res = n
print(res)