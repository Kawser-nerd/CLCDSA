#!/usr/bin/env python3

# Google Code Jam Round 1B 2015
# Problem A. Counter Culture
# Solution in Python
# By Smithers

def solvePow10(p):
    y = 10
    i = 1
    while i < p:
        i += 1
        y += 10**(i//2) + 10**((i+1)//2) - 1
    return y

for x in range(1, int(input()) + 1):
    N = int(input())
    
    N1 = N
    lastInc = 0
    if N1 % 10 == 0:
        N1 -= 1
        lastInc = 1
    
    l = len(str(N1))
    
    if l == 1:
        y = N1
    else:
        y = solvePow10(l-1)
        
        y1 = N1 - 10 ** (l-1)
        
        l2 = l // 2
        sN1 = str(N1)
        sN1a = sN1[l2:]
        sN1b = ''.join(reversed(sN1[:l2]))
        y2 = int(sN1b) + 1 + int(sN1a) - 1
    
        y += min(y1, y2)
    
    y += lastInc
    
    print('Case #' + str(x) + ':', y)
