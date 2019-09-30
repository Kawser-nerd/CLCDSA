from __future__ import print_function, division
from collections import Counter

def overlap_shift(s):
    for i in range(len(s)):
        if s.startswith(s[i + 1:]):
            return i + 1

def tc(tci):
    [klen, tlen, s] = map(int, raw_input().split())
    keyboard = raw_input()
    target = raw_input()
    assert klen == len(keyboard)
    assert tlen == len(target)
    assert s >= tlen
    sol = 0.0
    counter = Counter(keyboard)
    if all(t in counter for t in target):
        sh = overlap_shift(target)
        occs = 1 + (s - tlen) // sh
        p = 1.0
        for t in target:
            p *= counter[t] / klen
        sol = occs - p * (s - tlen + 1)

    print("Case #{}: {:.15f}".format(tci, sol))

tcn = int(raw_input())
for tci in range(1, tcn+1): tc(tci)
