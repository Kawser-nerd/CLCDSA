#!/usr/bin/env python3
N = int(input())
A, B = map(int, input().split())

ans = True
if N > A:
    if A == B:
        ans = N % (A + 1) != 0
    else:
        ans = A > B
print(['Aoki', 'Takahashi'][ans])