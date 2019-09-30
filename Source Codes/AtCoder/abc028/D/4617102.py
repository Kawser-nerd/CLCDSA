#!/usr/bin/env python3
N, M = map(int, input().split())
l = M - 1
r = N - M
print((6 * l * r + 3 * l + 3 * r + 1) / N**3)