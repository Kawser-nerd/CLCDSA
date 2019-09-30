import os
import heapq
import math
        
def getResultMultiLine():
    pass

def check(queue, checked, line):
    # print line
    if line[:4] not in checked:
        queue.append(line)
        checked.add(line[:4])
    

def getResult(hp, att, hpK, attK, b, d):
    hp0 = hp
    queue = [(hp, att, hpK, attK, 0)]
    index = 0
    checked = set()
    while index < len(queue):
        (hp, att, hpK, attK, i) = queue[index]
        attK1 = max(attK - d, 0)
        if hpK <= att:
            # print queue
            return i + 1
        if hp - attK <= 0:
            if hp - attK1 > 0:
                check(queue, checked, (hp - attK1, att, hpK, attK1, i + 1))
            if hp0 - attK > 0:
                check(queue, checked, (hp0 - attK, att, hpK, attK, i + 1))
        else:
            check(queue, checked, (hp - attK, att, hpK - att, attK, i + 1))
            if b > 0:
                check(queue, checked, (hp - attK, att + b, hpK, attK, i + 1))
            if d > 0:
                check(queue, checked, (hp - attK1, att, hpK, attK1, i + 1))
        index += 1
    return "IMPOSSIBLE"
            
        
    

input = """
4
11 5 16 5 0 0
3 1 3 2 2 0
3 1 3 2 1 0
2 1 5 1 1 1
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
        iLine += 1

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
