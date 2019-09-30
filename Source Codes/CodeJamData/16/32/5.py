#!/usr/bin/env python

from sys import stdin, stderr
from struct import pack

def Solve(B, M):
    MaxM = 1 << B - 2
    if MaxM < M:
        print 'IMPOSSIBLE'
        return
    print 'POSSIBLE'
    M -= 1
    print '0' + '1' * (B - 1)
    for b in range(B - 2):
        print '0' * (b + 2) + '1' * (B - b - 3) + str(M % 2)
        M >>= 1
        pass
    print '0' * B
    return

for T in range(int(stdin.readline())):
    B, M = stdin.readline().split()
    B = int(B)
    M = int(M)

    print 'Case #%d:' % (T+1),
    Solve(B, M)
