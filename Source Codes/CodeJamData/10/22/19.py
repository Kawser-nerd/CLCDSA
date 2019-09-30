#!/usr/bin/python

import sys

def line():
    return sys.stdin.readline()[:-1]

def readList():
    return map(eval,line().split())

if __name__ == '__main__':
    numberOfCases = eval(line())
    for caseNumber in range(numberOfCases):
        N, K, B, T = readList()
        X = readList()
        V = readList()

        makesIt = [(B - X[i] + V[i] - 1)/V[i] <= T for i in range(N)]
        alreadyThere = 0
        while len(makesIt) > 0 and makesIt[-1]:
            alreadyThere += 1
            makesIt.pop(-1)

        needed = 0
        i = len(makesIt) - 1
        while i >= 0 and alreadyThere < K:
            if makesIt[i]:
                needed += len(makesIt) - i - 1
                makesIt.pop(i)
                alreadyThere += 1
            else:
                i -= 1

        print "Case #" + str(caseNumber+1) + ": " + (str(needed).replace('L','') if alreadyThere >= K else 'IMPOSSIBLE')
