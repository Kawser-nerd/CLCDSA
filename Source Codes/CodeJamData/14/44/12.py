#!/usr/bin/env python3

from itertools import product

for ti in range(1, int(input())+1):
    m, n = map(int, input().split())
    s = [input() for i in range(m)]
    s.sort()
    
    most = 0
    ways = 0
    for perm in product(range(n), repeat = m):
        if not all([i in perm for i in range(n)]):
            continue
        nodes = 0
        for i in range(n):
            x = ''
            nodes += 1
            for j in range(m):
                if perm[j] != i:
                    continue
                y = s[j]
                k = 0
                while k < len(x) and k < len(y) and x[k] == y[k]:
                    k += 1
                nodes += len(y) - k
                x = y
        if nodes > most:
            most = nodes
            ways = 1
        elif nodes == most:
            ways += 1
    
    print('Case #' + str(ti) + ':', most, ways)
