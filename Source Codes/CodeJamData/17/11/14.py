import os
import heapq
import math
import re

def fillLine(qLine):
    i = 0
    r = ""
    while qLine[i] == "?":
        i += 1
    r = qLine[i] * i
    iLast = i
    while i < len(qLine):
        if qLine[i] == "?":
            r += qLine[iLast]
        else:
            r += qLine[i]
            iLast = i
        i += 1
    return r

def getResultMultiLine(h, w, qLines):
    emptyLines = []
    for i in range(h):
        res = (qLines[i].replace("?", "") == "")
        emptyLines.append(res)
    for i in range(h):
        if not emptyLines[i]:
            qLines[i] = fillLine(qLines[i])
    i = 0
    while emptyLines[i]:
        i += 1
    for j in range(i):
        qLines[j] = qLines[i]
    iLast = i
    while i < h:
        if emptyLines[i]:
            qLines[i] = qLines[iLast]
        else:
            iLast = i
        i += 1
    return qLines

def getResult(n, k):
    pass        
    

input = """
3
4 3
A??
?CD
???
B??
3 4
CODE
????
?JAM
2 2
CA
KE
"""



if __name__ == "__main__":
    problem = os.path.basename(__file__)[0]
    folder = os.path.dirname(__file__)
    nameParts = [os.path.join(folder, problem + "-" + name) for name in ["test", "small-attempt0", "large"]]
    namePart = None
    for namePart1 in nameParts:
        if os.path.exists(namePart1 + ".in"):
            namePart = namePart1
            print "Using " + namePart
    if namePart is None:
        lines = [s for s in input.split("\n") if len(s) > 0]
    else:
        lines = [s[:len(s) - 1] for s in open(namePart + ".in", "r")]
    count = int(lines[0])
    resultLines = []
    iLine = 1
    
    multiLineResult = True
    
    for iTry in range(count):
        iLastResult = len(resultLines)

        # input = ...
        # iLine += 1

        # input = map(int, lines[iLine].split())
        
        testCase = map(int, lines[iLine].split())
        (h, w) = testCase
        iLine += 1
        qLines = []
        for i in range(h):
            qLines.append(lines[iLine])
            iLine += 1
        testCase.append(qLines)

        if multiLineResult:
            resultLines.append("Case #" + str(iTry + 1) + ":")
            resultLines += map(str, getResultMultiLine(*testCase))
        else:
            resultLines.append("Case #" + str(iTry + 1) + ": " + str(getResult(*testCase)))
        for j in range(iLastResult, len(resultLines)):
            print resultLines[j]
    if namePart is not None:
        with open(namePart + ".out", "wt") as oFile:
            for resultLine in resultLines:
                oFile.write(resultLine + "\n")
