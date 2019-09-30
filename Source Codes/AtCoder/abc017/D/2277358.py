# -*- coding: utf-8 -*-
MOD = 10**9+7
N, M = map(int, input().split())

F = [0]*(N)
L = [-1]*(M+1)
P = [0]*(N)

for i in range(N):
    f = int(input())
    F[i] = f

l = 0
for i in range(N):
    f = F[i]
    if L[f] == -1:
        P[i] = l
        L[f] = i
    else:
        for j in range(l, L[f]+1):
            L[F[j]] = -1
        l = j + 1
        P[i] = l
        L[f] = i

DP = [1]*(N+2)
DP[0] = 0
for i in range(N):
    DP[i+2] = (DP[i+1] + (DP[i+1] - DP[P[i]]))%MOD

print((DP[i+1] - DP[P[i]])%MOD)