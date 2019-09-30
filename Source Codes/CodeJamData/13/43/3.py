#!/usr/bin/python

import sys
import re
import math
import string

f = open(sys.argv[1],'r')
num = int(f.readline())

def inc(l):
    ns = {0:0}
    for x in l:
        ns[x] = 0
        for y in ns:
            if x > y:
                ns[x] = max(ns[y]+1, ns[x])
    return max([ns[x] for x in ns])

def dec(l):
    ns = {10000:0}
    for x in l:
        ns[x] = 0
        for y in ns:
            if x < y:
                ns[x] = max(ns[y]+1, ns[x])
    return max([ns[x] for x in ns])


def ins(li, n, a, b):
    #print li, n
    for i in range(len(li)):
        if li[i] < n:
            continue
        #print i, a[i], b[i], 1+sum([1 for j in xrange(i) if li[j] < n]), 1+sum([1 for j in xrange(i+1, len(li)) if li[j] < n]), 1+inc([li[j] for j in xrange(i) if li[j] < n]), 1+dec([li[j] for j in xrange(i+1, len(li)) if li[j] < n])
        if a[i] == 1+inc([li[j] for j in xrange(i) if li[j] < n]) and b[i] == 1+dec([li[j] for j in xrange(i+1, len(li)) if li[j] < n]):
            #print li, i, n
            li[i] = n
            if max(li) == n:
                return li
            r = ins(li, n+1, a, b)
            if r:
                return r
            li[i] = 10000
    #print "ret F"
    return False

for i in xrange(num):
    N = int(f.readline())
    l = f.readline()
    a = [int(x) for x in l.split()]
    l = f.readline()
    b = [int(x) for x in l.split()]
    li = [10000]*N
    r = ins(li, 1, a, b)
    print 'Case #{}:'.format(i+1), ' '.join([str(x) for x in r])
