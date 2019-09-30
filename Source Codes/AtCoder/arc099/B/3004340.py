#!/usr/bin/env python3
import fractions
s = lambda n: sum(map(int, str(n)))

cands = []
for a in range(1000):
    for b in range(20):
        cands += [ a * 10 ** b + (10 ** b - 1) ]

snukes = []
min_f = float('inf')
for n in reversed(sorted(cands)):
    if n == 0 or (snukes and snukes[-1] == n):
        continue
    f = fractions.Fraction(n, s(n))
    if f <= min_f:
        min_f = f
        snukes += [ n ]
snukes.reverse()

k = int(input())
for n in snukes[: k]:
    print(n)