#!/usr/bin/env python3
N = int(input()) + 1
L = len(str(N))

ans = 0
for i in range(1, L + 1):
    c = (N // 10**i) * 10**(i - 1)
    r = N % 10**i - 10**(i - 1)
    ans += c
    if r > 0:
        ans += min(10**(i - 1), r)

print(ans)