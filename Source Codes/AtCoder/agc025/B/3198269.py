# -*- coding: utf-8 -*-
from sys import stdin
import math

in_strings = lambda: stdin.readline()[:-1] # s = in_strings()
in_int = lambda: int(stdin.readline()) # N = in_int()
in_intlist = lambda: list(map(int, stdin.readline().split())) # List = in_intlist()

N, A, B, K = in_intlist()
NUM = 998244353

# ??
Inv = [0 for _ in range(N)]
for i in range(N):
    Inv[i] = pow(i+1, NUM-2, NUM)

# Combination
Comb = [0 for _ in range(N+1)]
Comb[0] = 1
for i in range(1, N+1):
    Comb[i] = (Comb[i-1] * (N-i+1) * Inv[i-1]) % NUM


ans = 0
for i in range(N+1):
    if ((K - i*A) % B == 0) and (0 <= (K - i*A) // B <= N):
        ans = (ans + Comb[i]*Comb[(K - i*A) // B]) % NUM 

print(ans)