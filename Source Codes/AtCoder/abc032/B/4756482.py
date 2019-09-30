# -*- coding: utf-8 -*-
s = input()
k = int(input())

tmp = []
for i in range(len(s) - k + 1):
    tmp.append(s[i:i + k])
print(len(set(tmp)))