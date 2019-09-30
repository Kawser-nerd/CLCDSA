# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int,input().split()))

a.sort()

cnt = 0
for i in range(1,len(a)):
    if a[i-1] == a[i]:
        cnt += 1

if cnt % 2 == 0:
    print(n - cnt)
else:
    print(n - cnt - 1)