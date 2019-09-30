#!/usr/bin/env python

from sys import stdin, stderr
from struct import pack

def Solve(J, P, S, K):
    K = min(S, K)
    print J * P * K
    #print 'JPSK:', J, P, S, K
    for j in range(J):
        for p in range(P):
            for k in range(K):
                print j+1, p+1, ((j+p+k) % S) + 1
                pass
            pass
        pass
    return

for T in range(int(stdin.readline())):
    J, P, S, K = [int(wd) for wd in stdin.readline().split()]

    print 'Case #%d:' % (T+1),
    Solve(J, P, S, K)
