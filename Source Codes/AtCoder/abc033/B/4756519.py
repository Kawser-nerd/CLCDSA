# -*- coding: utf-8 -*-
N = int(input())
S = [''] * N
P = [0] * N
for i in range(N):
    S[i], P[i] = input().split()
    P[i] = int(P[i])

flag = 0
for i in range(N):
    if P[i] > sum(P) / 2:
        print(S[i])
        flag = 1
if flag == 0:
    print('atcoder')