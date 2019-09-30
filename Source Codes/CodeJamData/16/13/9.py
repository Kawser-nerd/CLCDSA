import jam
import sys
sys.setrecursionlimit(10000)

def largestCycle(b):
    longestCycleLength = 0
    for start in b:
        visited = {start}
        current = start
        while True:
            current = b[current]
            if current in visited:
                if current == start:
                    cycleLength = len(visited)
                    if cycleLength > longestCycleLength:
                        longestCycleLength = cycleLength
                break
            visited.add(current)
    return longestCycleLength

def pairs(b):
    paired = set()
    for p in b:
        q = b[p]
        if b[q] == p:
            paired.add(p)
            paired.add(q)
    return paired

def pairGeneration(b):
    currentGen = pairs(b)
    anyGen = set(currentGen)
    while len(currentGen) > 0:
        lastGen = currentGen
        currentGen = set()
        for p in b:
            if p not in anyGen and b[p] in lastGen:
                lastGen.remove(b[p])
                currentGen.add(p)
                anyGen.add(p)
    return len(anyGen)

def longestChainEndingIn(p, b, available):
    longestChainLength = 0
    l = set()
    for a in available:
        visited = {a}
        current = a
        while True:
            current = b[current]
            if current == p:
                chainLength = len(visited)
                if chainLength > longestChainLength:
                    longestChainLength = chainLength
                    l = set(visited)
                break
            if current in visited or current not in available:
                break
            visited.add(current)
    return longestChainLength

def pairChain(b):
    paired = pairs(b)
    unpaired = set(b.keys()).difference(paired)
    count = len(paired)
    for p in paired:
        count += longestChainEndingIn(p, b, unpaired)
    return count

def solve(case):
    N = case.readInt()
    b = dict()
    for i in range(N):
        q = case.readInt()
        b[i + 1] = q
    x = largestCycle(b)
    y = pairChain(b)
    print(x, y)
    return max(x, y)

jam.run("C-large.in", solve)
