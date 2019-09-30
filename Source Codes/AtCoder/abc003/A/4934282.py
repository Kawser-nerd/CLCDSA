# -*- coding: utf-8 -*-

N = int(input())

s = 0
for i in range(N):
    s += (10000*(i+1)) * (1/N)

print(int(s))