#!/usr/bin/env python

from sys import stdin, stderr
from struct import pack

def Solve(P):
    ret = ''
    P.sort()
    P.reverse()
    #print P
    for i in range(P[0][0]):
        for j in range(len(P)):
            if P[j][0] == 0:
                del P[j:]
                break
            P[j][0] -= 1
            ret += P[j][1]
            pass
        pass
    ret2 = ''
    lenret = len(ret)
    if lenret % 2 == 1:
        ret2 += ret[-1] + ' '
        lenret -= 1
    for i in range(lenret / 2):
        ret2 += ret[lenret - 2 * i - 1] + ret[lenret - 2 * i - 2] + ' '
        pass

    return ret2[:-1]

for T in range(int(stdin.readline())):
    N = int(stdin.readline())
    wds = stdin.readline().split()
    P = [[int(c), pack('b', i + 65)] for i, c in enumerate(wds)]

    print 'Case #%d:' % (T+1),
    print Solve(P)
