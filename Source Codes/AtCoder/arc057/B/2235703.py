# -*- coding: utf-8 -*-

def inpl(): return list(map(int, input().split()))
N, K = inpl()
A = [int(input()) for _ in range(N)]
S = [0 for _ in range(N+1)]

tmp = 0
for i, a in enumerate(A):
    tmp += a
    S[i] = tmp

if sum(A) == K:
    print(1)
    exit()

DP = [0, 1] + [10**10]*(N-1)  #x??????????????????

for i in range(1, N):
    DP2 = [0, 1] + [10**10]*(N-1)
    for j in range(1, i+1):
        tmp = DP[j] * (S[i] - S[i-1]) // S[i-1] + 1
        DP2[j+1] = min(DP[j+1], tmp + DP[j], DP2[j+1])
    DP = DP2

for i, d in list(enumerate(DP))[::-1]:
    if d <= K:
        print(i)
        break
else:
    print(1)