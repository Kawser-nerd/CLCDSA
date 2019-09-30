# -*- coding: utf-8 -*-

h,w = map(int,input().split())
a = [0] * h
for i in range(h):
    a[i] = list(input())

delete = []
for i in range(h):
    if not("#" in a[i]):
        delete.append(i)

diff = 0
for i in range(len(delete)):
    del a[delete[i] - diff]
    diff += 1

bucket = [0] * len(a[0])
for i in range(len(a)):
    for j in range(len(a[0])):
        if a[i][j] == "#":
            bucket[j] += 1

delete = []
for i in range(len(bucket)):
    if bucket[i] == 0:
        delete.append(i)

diff = 0
for i in range(len(delete)):
    for j in range(len(a)):
        del a[j][delete[i] - diff]
    diff += 1

for i in range(len(a)):
    temp = "".join(a[i])
    print(temp)