#!/usr/bin/env python3
N = int(input())
A = list(map(int, input().split()))

c = [0] * N
for x in A:
    c[x] += 1

ans = 1
if A[0] != 0 or c[0] > 1:
    ans = 0

MOD = int(1e9 + 7)
for i in range(N)[1:]:
    if c[i] == 0:
        continue
    ans *= pow(2, c[i] * (c[i] - 1) // 2, MOD)
    ans *= pow(pow(2, c[i - 1], MOD) - 1, c[i], MOD)
    ans %= MOD
print(int(ans))