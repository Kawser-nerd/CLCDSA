# -*- coding: utf-8 -*-

tmp = True

N = int(input())
w = [input() for i in range(N)]
if len(set(w)) != N:
    tmp = False
for i in range(N-1):
    if w[i][-1] != w[i+1][0]:
        tmp = False
print('Yes'if tmp else 'No')