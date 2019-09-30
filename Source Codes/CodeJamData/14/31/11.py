#!/usr/bin/python

from fractions import gcd   

def possible(q):
    for i in range(41):
        if q == 2**i:
            return True
    return False

def doit():
    (N,M) = raw_input().split("/")
    p = int(N)
    q = int(M)
    gc = gcd(p,q)
    p /= gc
    q /= gc
    
    if not possible(q):
        return "impossible"
        
    for i in range(41):
        if p * (2**i) >= q :
            return i
            
    

cases = input()
for case in range(1, cases+1):
    
    print ("Case #" + str(case) + ":"),
    print doit()
