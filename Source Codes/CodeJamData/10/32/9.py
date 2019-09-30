#!/usr/bin/env python

from math import *

def main():
    fin = open('large.in','r')
    fout = open('large.out','w')
    tn = int(fin.readline())
    for test in range(tn):
        l,p,c = fin.readline().split(' ')
        l = int(l)
        p = int(p)
        c = int(c)
        temp1 = log(1. * p / l) / log(c)
        ans = int(ceil(log(temp1) / log(2)))
        if ans <= 0:
            ans = 0
        fout.write('Case #%d: %d\n' % (test+1, ans))
    fin.close()
    fout.close()

if __name__=='__main__':
    main()
