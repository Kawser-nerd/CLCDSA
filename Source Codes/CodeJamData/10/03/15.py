#!/usr/bin/env python
# -*- coding: utf-8 -*-



if __name__ == "__main__":
    
    inFile = open("C-large.in","r")
    outFile = open("realtest.out","w")
    
    caseNum = int(inFile.readline())
    
    for i in range(1,caseNum+1):        
        items = inFile.readline().replace("\n","").split(" ")
        R = int(items[0])
        k = int(items[1])
        N = int(items[2])
        
        items = inFile.readline().replace("\n","").split(" ")

        if len(items) != N:
            print "guest number error."
            continue
        
        dataList = []
        for item in items:
            dataList.append(int(item))

        roundData = []
        occurInfo = {}
        posCnt = 0               
        totalCnt = 0
        
        while posCnt not in occurInfo:
            
            testSum = 0
            tmp_cnt = 0
            while tmp_cnt<N and testSum + dataList[(posCnt + tmp_cnt)%N] <= k:
                testSum += dataList[(posCnt + tmp_cnt)%N]
                tmp_cnt += 1

            roundData.append(testSum)    
            occurInfo[posCnt] = totalCnt            
            posCnt = (posCnt + tmp_cnt)%N

            totalCnt += 1
            
            
        roundSum = 0
        loopLen = len(roundData) - occurInfo[posCnt]
        for j in range(occurInfo[posCnt],len(roundData)):
            roundSum += roundData[j]

        totalSum = 0
        for j in range(occurInfo[posCnt]):
            totalSum += roundData[j]

        for j in range((R-occurInfo[posCnt])%loopLen):
            totalSum += roundData[j+occurInfo[posCnt]]
            
        totalSum += ((R-occurInfo[posCnt])/loopLen) * roundSum         
            
            
        outFile.write("Case #%d: %d\n" % (i,totalSum))
        
        
    outFile.close()
    inFile.close()
