#!/usr/bin/env python3

import numpy as np

MOD = 1000000007

def main():
    n = int(input())
    tn = [int(input()) for i in range(n)]
    cnt = {}
    for t in tn:
        if t in cnt:
            cnt[t] += 1
        else:
            cnt[t] = 1
    now = 0
    pena = 0
    for t in sorted(cnt):
        for i in range(cnt[t]):
            now += t
            pena += now

    ways = 1
    for t in cnt:
        ways *= fact(cnt[t])
        ways %= MOD

    print(pena)
    print(ways)

def fact(n):
    fa = 1
    for k in range(1, n + 1):
        fa *= k
        fa %= MOD
    return fa

main()