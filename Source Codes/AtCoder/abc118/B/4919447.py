# -*- coding: utf-8 -*-


N, M = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]
res = [0] * M
for i in range(N):
    for j in A[i][1:]:
        res[j - 1] += 1
print(res.count(N))