# -*- coding: utf-8 -*-

N = int(input())
count = 0

for i in range(1, N + 1):
    a = []
    all_odd = 0
    for j in range(1, i + 1):
        if i % j == 0:
            a.append(j)
    for k in a:
        if k % 2 == 0:
            all_odd += 1
    if all_odd == 0 and len(a) == 8:
        count += 1

print(count)