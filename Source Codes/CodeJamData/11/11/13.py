#!/usr/bin/env python

from sys import argv

P,B = 'Possible','Broken'

def pg100(a):
    b = 100
    for y in (2,2,5,5):
        if (a % y) == 0:
            a /= y
            b /= y
    return b

def check(n,pd,pg):
    if pg == 100:
        a = P if pd == 100 else B
    elif pg == 0:
        a = P if pd == 0 else B
    elif pd == 0:
        a = P
    else:
        a = P if pg100(pd) <= n else B
    return a

f = open(argv[1],'r')
p = int(f.readline())
for x in xrange(p):
    n,pd,pg = map(int,f.readline().split())
    print 'Case #%d: %s' % (x+1,check(n,pd,pg))
f.close()
