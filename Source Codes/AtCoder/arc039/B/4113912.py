#!/usr/bin/env python3
from operator import mul
from itertools import accumulate

MOD = int(10 ** 9 + 7)

N, K = map(int, input().split())

fact = [1] + list(map(lambda x: x % MOD, accumulate(range(1, N + K), mul)))
finv = [pow(x, MOD - 2, MOD) for x in fact]

if N > K:
    ans = fact[N + K - 1] * finv[K] * finv[N - 1] % MOD
else:
    R = K % N
    ans = fact[N] * finv[R] * finv[N - R] % MOD
print(ans)