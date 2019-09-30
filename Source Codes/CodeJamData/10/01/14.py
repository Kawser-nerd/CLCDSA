#!/usr/bin/env python
# -*- coding: utf-8 -*-



if __name__ == "__main__":
    
    inFile = open("A-large.in","r")
    outFile = open("realtest.out","w")
    
    caseNum = int(inFile.readline())
    
    for i in range(1,caseNum+1):        
        items = inFile.readline().replace("\n","").split(" ")
        N = int(items[0])
        K = int(items[1])

        lightFlag = 1

        for j in range(N):
            if K%2 == 0:
                lightFlag = 0
                break;
            else:
                K /= 2

        if lightFlag == 1:
            outFile.write("Case #%d: ON\n" % (i,))
        else:
            outFile.write("Case #%d: OFF\n" % (i,))
        
        
        
    outFile.close()
    inFile.close()
