# -*- coding: utf-8 -*-
n,m = map(int,input().split())
ab = [[0,0] for _ in range(m)]
for i in range(m):
    ab[i][1],ab[i][0] = map(int,input().split())

ab.sort()

cnt = 0
before = 0
for i in range(m):
    if cnt >= 1 and ab[i][1] < before:
        pass
    else:
        before = ab[i][0]
        cnt += 1

print(cnt)