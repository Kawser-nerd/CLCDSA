#!/usr/bin/env python3
import numpy as np
import sys

names = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
a = np.zeros((26, 10))
for i in range(10):
    for c in names[i]:
        a[ord(c) - ord('A'), i] += 1

T = int(input())
for case in range(T):
    s = input()
    b = np.zeros(26)
    for c in s:
        b[ord(c) - ord('A')] += 1
    x = np.linalg.lstsq(a, b)[0]
    print('Case #{}: '.format(case + 1), end='')
    for i in range(10):
        for j in range(int(np.round(x[i]))):
            print(i, end='')
    print()
