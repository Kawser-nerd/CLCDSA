#!/usr/bin/env python
# -*- coding: utf-8 -*-

def dcn(t,v):
    global dn
    if (t,v) in dn:
        return dn[(t,v)]
    rtv = 0
    if v>t:
        rtv = 0
    elif v==t:
        rtv = 1
    elif v ==0:
        rtv = 1
    elif v ==1 :
        rtv = t
    else:
        rtv = dcn(t-1,v-1) + dcn(t-1, v)
        
    dn[(t,v)] = rtv
    return rtv

dn = {}
fn = {}

if __name__ == "__main__":
    
    inFile = open("C-large.in","r")
    outFile = open("practice.out","w")
    
    fn[(2,1)] = 1
    
    for j in range (3,501):
        print j
        fn[(j,1)] = 1
        fn[(j,j-1)] = 1
        for k in range(2,j-1):
            fn[(j,k)] = 0
            for u in range(1,k):
                fn[(j,k)] += (dcn(j-k-1,u-1) *  fn[(k,k-u)])%100003
        
        
    caseNum = int(inFile.readline())
    for i in xrange(1,caseNum+1):
             
        n = int(inFile.readline())
        rtv = 0
        for j in range (1,n):
            rtv += fn[(n,j)]%100003
        outFile.write("Case #%d: %d\n" % (i,rtv%100003))
            
       
        
    outFile.close()
    inFile.close()
