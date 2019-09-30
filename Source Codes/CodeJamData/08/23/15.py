#!/usr/bin/python

import sys

def readdata():
    def rl():
        return sys.stdin.readline().strip().split(' ')
    n = int(rl()[0])
    cases = []
    for i in range(n):
        K = int(rl()[0])
        il = [int(x) for x in rl()]
        case = (K,il[1:il[0]+1])
        cases.append(case)
    return cases

case_number = 1
for case in readdata():
    sc = case[0]
    si = range(sc)
    sv = [0]*sc
    cv = 1
    ci = 0
    for z in xrange(sc):
        ci += z
        ci = ci % len(si)
        sv[si[ci]] = z + 1
        si.remove(si[ci])
    print 'Case #' + str(case_number) + ':',' '.join([str(sv[x-1]) for x in case[1]])
    case_number += 1
