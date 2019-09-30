#!/usr/bin/env python3

import numpy as np

def main():
    n, m = map(int, input().split())
    sts = []
    for i in range(m):
        s1, t1 = map(int, input().split())
        sts.append((s1, t1))

    start_at = [set() for x0 in range(n)]
    end_at = [set() for x0 in range(n)]
    for i in range(m):
        s1, t1 = sts[i]
        start_at[s1 - 1].add(i)
        end_at[t1 - 1].add(i)

    neglectable = [1 for i in range(m)]
    cleaners = set()
    for x0 in range(n):
        cleaners |= start_at[x0]
        if len(cleaners) == 1:
            for i in cleaners:
                neglectable[i] = 0
        cleaners -= end_at[x0]

    print(np.sum(neglectable))
    for i in range(m):
        if neglectable[i] == 1:
            print(i + 1)

main()