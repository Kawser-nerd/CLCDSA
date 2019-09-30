#!/usr/bin/env python3
N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
cnt = 0
ans = 0
for i in range(1, N):
    cnt = (A[i - 1] < A[i]) * (cnt + 1)
    if cnt >= K - 1:
        ans += 1
print(ans + (K == 1))