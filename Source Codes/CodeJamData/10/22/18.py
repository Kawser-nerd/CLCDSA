#!/usr/bin/env python
# -*- coding: utf-8 -*-



if __name__ == "__main__":
    
    inFile = open("B-large.in","r")
    outFile = open("practice.out","w")
    
           
        
    caseNum = int(inFile.readline())
    for i in xrange(1,caseNum+1):
        rtv = 0
        
        N, K, B, T = tuple(map(int,inFile.readline().strip().split()))
        X = map(int,inFile.readline().strip().split())
        V = map(int,inFile.readline().strip().split())

        tc = []        
        for j in range(N):            
            tmp_t = (B-X[j])/float(V[j])
            tc.append((B-X[j])/float(V[j]))

        
        rtv = 0
        fg = 0
        lg = 0
        for j in range(N):
            h = N-j-1
            if tc[h]>T:
                lg+=1
                
            else:
                fg+=1
                rtv+=lg
                
                if fg >= K:
                    
                    break
        if fg<K:
            outFile.write("Case #%d: IMPOSSIBLE\n" % (i,))
        else:
            outFile.write("Case #%d: %d\n" % (i,rtv))
        
            
       
        
    outFile.close()
    inFile.close()
