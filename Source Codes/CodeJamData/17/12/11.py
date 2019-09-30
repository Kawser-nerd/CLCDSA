import os
import heapq
import math

def getResultMultiLine():
    pass

def getLowHigh(size, rValue):
    # low * rValue >= 0.9 * size, high * rValue <= 1.1 * size
    low = (size * 10 - 1) / (11 * rValue) + 1
    high = (size * 10) / (9 * rValue)
    return (low, high)


def getResult(n, pSize, r, matrix):
    low = [[0 for p in range(pSize)] for i in range(n)]
    high = [[0 for p in range(pSize)] for i in range(n)]
    mSorted = []
    for i in range(n):
        sizes = sorted(matrix[i])
        mSorted.append(sizes)
        for p in range(pSize):
            (low1, high1) = getLowHigh(sizes[p], r[i])
            low[i][p] = low1
            high[i][p] = high1
    found = 0
    indices = [0 for i in range(n)]
    while True:
        iMaxLow = -1
        maxLow = 0
        for i in range(n):
            if low[i][indices[i]] > maxLow:
                maxLow = low[i][indices[i]]
                iMaxLow = i
        ok = True
        for i in range(n):
            if i != iMaxLow:
                while indices[i] < pSize and maxLow > high[i][indices[i]]:
                    indices[i] += 1
                if indices[i] == pSize:
                    return found
                if maxLow < low[i][indices[i]]:
                    ok = False
                    break
        if ok and maxLow <= high[iMaxLow][indices[iMaxLow]]:
            for i in range(n):
                value = maxLow * r[i]
                size = mSorted[i][indices[i]]                
                if value * 9 <= size * 10 and value * 11 >= size * 10:
                    pass
                else:
                    print "Mismatch: ", i, maxLow, r[i], mSorted[i][indices[i]]
            found += 1
            for i in range(n):
                indices[i] += 1
                if indices[i] == pSize:
                    return found
        else:
            indices[iMaxLow] += 1
            if indices[iMaxLow] == pSize:
                return found
            
        

input = """
6
2 1
500 300
900
660
2 1
500 300
1500
809
2 2
50 100
450 449
1100 1101
2 1
500 300
300
500
1 8
10
11 13 17 11 16 14 12 18
3 3
70 80 90
1260 1500 700
800 1440 1600
1700 1620 900
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
    
    multiLineResult = False
    
    for iTry in range(count):
        iLastResult = len(resultLines)

        # input = ...
        # iLine += 1

        # input = map(int, lines[iLine].split())
        
        testCase = map(int, lines[iLine].split())
        (n, p) = testCase
        iLine += 1
        r = map(int, lines[iLine].split())
        iLine += 1
        matrix = []
        for i in range(n):
            matrix.append(map(int, lines[iLine].split()))
            iLine += 1
        testCase.append(r)
        testCase.append(matrix)

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
