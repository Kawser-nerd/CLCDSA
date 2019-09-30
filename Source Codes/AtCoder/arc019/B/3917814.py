#!/usr/bin/env python3
A = input()
N = len(A)

cnt = 0
for i in range(N // 2):
    if A[i] != A[-1 - i]:
        cnt += 1

ans = N // 2 * 2 * 25
ans -= 2 * (cnt == 1)
ans += N % 2 * 25 * (cnt > 0)
print(ans)