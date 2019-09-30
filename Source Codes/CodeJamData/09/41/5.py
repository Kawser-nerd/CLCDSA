# -*- coding: utf-8 -*-
from sys import stdin

def main():
    n = int(stdin.readline())
    l = [('1' + stdin.readline().strip()).rfind('1') for _ in xrange(n)]
    #print l
    def first(x):
        for i, v in enumerate(l):
            if v <= x+1:
                return i
    s = 0
    for i in xrange(n):
        f = first(i)
        del l[f]
        s += f
    return str(s)

tno = int(stdin.readline())
for i in xrange(0, tno):
    print "Case #%d: %s"%(i+1, main())
