#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

if __name__ == '__main__':
    numberOfCases = eval(line())
    for caseNumber in range(numberOfCases):
        R = eval(line())
        currentWorld = set()
        for k in range(R):
            X1, Y1, X2, Y2 = readList()
            for i in range(X1,X2+1):
                for j in range(Y1,Y2+1):
                    currentWorld.add((i,j))
        time = 0
        while len(currentWorld) > 0:
            newWorld = set()
            for (i,j) in list(currentWorld):
                if (i,j-1) in currentWorld or (i-1,j) in currentWorld:
                    newWorld.add((i,j))
                if (i-1,j+1) in currentWorld and (i,j+1) not in currentWorld:
                    newWorld.add((i,j+1))
                if (i+1,j-1) in currentWorld and (i+1,j) not in currentWorld:
                    newWorld.add((i+1,j))
            currentWorld = newWorld
            time += 1
        print "Case #" + str(caseNumber+1) + ": " + str(time).replace("L","")
