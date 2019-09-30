#!/usr/bin/python

from fractions import *

def yf(x,y):
    t=gcd(x,y)
    return x/t,y/t

def ok(n,pd,pg):
    w1,d=yf(pd,100)
    if d>n:
        return False
    if pg==100:
        return pd==100
    if pg==0:
        return pd==0
    return True

T=int(input())
for tt in range(1,T+1):
    line=input().split()
    n=int(line[0])
    pd=int(line[1])
    pg=int(line[2])
    
    if ok(n,pd,pg):
        res="Possible"
    else:
        res="Broken"
    #res="%d %d %d %d" % (n, pd, pg, gcd(pd,pg))
    print("Case #%d: %s"%(tt,res))
