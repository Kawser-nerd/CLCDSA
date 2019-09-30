#!/usr/bin/python

from math import log,ceil

#infname='B-small-attempt0.in'
#oufname='B-small-attempt0.out'
infname='B-large.in'
oufname='B-large.out'


inf = open(infname)
ouf = open(oufname,'w')
read = inf.readline
out = ouf.write

t = int(read())

for test in range(t):
    l,p,c=map(int,read().split())
    cnt=0
    while l<p:
        cnt+=1
        l*=c
    out("Case #%d: %d\n"%(test+1,ceil(log(cnt,2))))
