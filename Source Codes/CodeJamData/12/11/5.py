#!/usr/bin/python
import os, sys, math

def prod(probs):
    x = 1.0
    for p in probs:
        x *= p
    return x

def calcFinish(A, B, probs):
    probRight = prod(probs)
    return ((probRight * (B - A + 1)) + ((1.0 - probRight) * (B - A + 1 + B + 1)))

def calcEnter(A, B, probs):
    return 1 + B + 1

# n = num to backspace
def calcBackspaces(A, B, n, probs):
    afterBackspace = calcFinish(A - n, B, probs[:A-n] )
    return n + afterBackspace

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        caseStr = fileLines[index][:-1]
        index += 1
        nums = [int(x) for x in caseStr.split(' ')]
        A = nums[0]
        B = nums[1]
        caseStr = fileLines[index][:-1]
        index += 1
        probs = [float(x) for x in caseStr.split(' ')]
        if len(probs) != A:
            print "WRONG LENGTH"
            sys.exit(1)
        finishStrokes = calcFinish(A, B, probs)
        enterStrokes = calcEnter(A, B, probs)
        numBackspaces = [calcBackspaces(A, B, n, probs) for n in range(1, A)]
        if len(numBackspaces) == 0:
            answer = min(finishStrokes, enterStrokes)
        else:
            answer = min(finishStrokes, enterStrokes, min(numBackspaces))
        #print caseStr
        print "Case #%d: %f" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
