#!/usr/bin/env python3

# Google Code Jam Round 3 2015
# Problem B. Smoothing Window
# Solution in Python
# By Smithers

for x in range(1, int(input()) + 1):
    N, K = map(int, input().split())
    sums = tuple(map(int, input().split()))
    
    a = [0] * K
    t = sums[0]
    for i in range(K):
        b = 0
        c = 0
        for j in range(i, N-K, K):
            c += sums[j+1] - sums[j]
            if c > a[i]:
                a[i] = c
            elif c < b:
                b = c
        a[i] -= b
        t += b
    
    t %= K
    for i in range(t):
        bestj = 0
        for j in range(1, K):
            if a[j] < a[bestj]:
                bestj = j
        a[bestj] += 1
    
    y = max(a)
    
    print('Case #' + str(x) + ':', y)
