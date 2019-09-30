# -*- coding: utf-8 -*-
#! python3

jungle = [int(s) for s in input().split()]
mine = [int(s) for s in input().split()]

total = 0
for i in range(7):
    total += max(jungle[i], mine[i])

print(total)