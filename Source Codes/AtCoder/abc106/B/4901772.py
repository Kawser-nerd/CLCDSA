# -*- coding: utf-8 -*-

N = int(input())
count = 0

for i in range(1, N + 1):
    a = []
    if i % 2 == 0:
        continue

    for j in range(1, i + 1):
        if i % j == 0:
            a.append(j)

    if len(a) == 8:
        count += 1

print(count)