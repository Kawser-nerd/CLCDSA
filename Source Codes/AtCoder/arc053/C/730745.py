# -*- coding:utf-8 -*-
import sys

n = int(input())

ls = [[int(num) for num in input().split()] for i in range(n)]

group1 = []
group2 = []
for i in range(n):
    if ls[i][0] < ls[i][1]:
        group1.append(ls[i])
    else:
        group2.append(ls[i])

group1.sort(key = lambda x: x[0])
group2.sort(key = lambda x:x[1], reverse = True)

mx = 0
tmp = 0

group1.extend(group2)

for magic in group1:
    tmp += magic[0]
    if tmp > mx :mx = tmp
    tmp -= magic[1]

print(mx)