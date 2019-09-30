# -*- coding: utf-8 -*-
N, M = map(int, input().split())
A = [[0]*M for _ in range(N)]
B = [list(map(int, input())) for _ in range(N)]

for i in range(N-2):
    for j in range(1, M-1):
        if B[i][j] == 0:
            continue
        b = B[i][j]
        A[i+1][j] += b
        B[i+1][j-1] -= b
        B[i+1][j+1] -= b
        B[i+2][j] -= b

A[-1] = B[-2]

for a in A:
    print(*a, sep="")