#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')
num = int(f.readline())

def cost(x, N):
    return x*N - (x-1)*x/2

for i in xrange(num):
    l = f.readline()
    N, M = [int(x) for x in l.split()]
    #print N,M
    pa = []
    for j in xrange(M):
        l = f.readline()
        pa.append([int(x) for x in l.split()])
    #print pa, [x[2]*cost(x[1]-x[0], N) for x in pa]
    oc = sum([x[2]*cost(x[1]-x[0], N) for x in pa])
    pa2 = dict()
    for x in pa:
        if pa2.has_key(x[0]):
            pa2[x[0]][0] += x[2]
        else:
            pa2[x[0]] = [x[2], 0]
        if pa2.has_key(x[1]):
            pa2[x[1]][1] += x[2]
        else:
            pa2[x[1]] = [0, x[2]]
    entry = dict()
    cc = 0
    for j in sorted(pa2):
        entry[j] = pa2[j][0]
        ex = pa2[j][1]
        while ex > 0:
            m = max(entry)
            if ex >= entry[m]:
                ex -= entry[m]
                cc += entry[m] * cost(j-m, N)
                del entry[m]
            else:
                entry[m] -= ex
                cc += ex * cost(j-m, N)
                ex = 0
            cc %= 1000002013

    print 'Case #{}:'.format(i+1), (oc - cc) % 1000002013
