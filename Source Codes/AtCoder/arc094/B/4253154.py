#!/usr/bin/env python3
# -*- coding: utf-8 -*-


import math

def solve(a, b):
    a, b = min(a, b), max(a, b)
    if a == b:
        return 2 * a - 2

    c = int(math.sqrt(a * b)) + 2
    while True:
        if c * c < a * b:
            if c * (c + 1) >= a * b:
                return 2 * c - 2
            else:
                return 2 * c - 1
        else:
            c -= 1

Q = int(input())
for _ in range(Q):
    a, b = map(int, input().split())
    print(solve(a, b))