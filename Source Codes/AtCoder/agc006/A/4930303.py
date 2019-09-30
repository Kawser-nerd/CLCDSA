# -*- coding: utf-8 -*-

n = int(input())
s = list(input())
t = list(input())

for i in range(n):
    match = True
    for j in range(n):
        if i + j < n:
            if s[i + j] != t[j]:
                match = False
    if match:
        if i == 0:
            print(n)
        else:
            print(n + i)
        break
else:
    print(n * 2)