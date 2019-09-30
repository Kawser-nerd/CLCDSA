#!/usr/bin/env python

from sys import stdin, stdout

C = int(stdin.readline())
for x in range(1, C+1):
    (N, K, B, T) = map(int, stdin.readline().split())
    Xi = map(int, stdin.readline().split())
    Vi = map(int, stdin.readline().split())
    assert(len(Xi) == len(Vi) == N)
    i = 0
    S = 0
    while i < K:
        k = N-i-1
        for j in range(k, -1, -1):
            if Xi[j] + Vi[j]*T >= B:
                break
        if Xi[j] + Vi[j]*T < B:
            break
        (Xi[k], Xi[j], Vi[k], Vi[j]) = (Xi[j], Xi[k], Vi[j], Vi[k])
        S += (k-j)
        i += 1
    
    if i < K:
        stdout.write('Case #%i: IMPOSSIBLE\n' % x)
    else:
        stdout.write('Case #%i: %i\n' % (x, S))

