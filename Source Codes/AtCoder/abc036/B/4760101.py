# -*- coding: utf-8 -*-
N = int(input())
s = []
for i in range(N):
    s.append(input())

ans = []
for i in range(N):
    ans.append('')
    for j in range(N):
        ans[i] += s[N - j - 1][i]
    print(ans[i])