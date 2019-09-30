inputFileName = "A-large.in"
outputFileName = "A-large.out"

Debug = False

import sys

def dprint(s) :
    if Debug :
        sys.stderr.write(s)

def solve(tree, index, M, V) :
    if index >= (M-1)/2 :
        if tree[index] == V :
            return 0
        else :
            return "IMPOSSIBLE"
    l = solve(tree, 2*index + 1, M, V)
    r = solve(tree, 2*index + 2, M, V)
    if V :
        try :
            AND = int(l+r)
        except :
            AND = "IMPOSSIBLE"
    else :
        try :
            AND = int(min([l, r]))
        except :
            AND = "IMPOSSIBLE"
    if V :
        try :
            OR = int(min([l, r]))
        except :
            OR = "IMPOSSIBLE"
    else :
        try :
            OR = int(l+r)
        except :
            OR = "IMPOSSIBLE"
    current = [OR, AND][int(tree[index][0])]
    change = [OR, AND][int(not tree[index][0])]
    if not tree[index][1] :
        return current
    else :
        
        if current == "IMPOSSIBLE" and change == "IMPOSSIBLE" :
            return "IMPOSSIBLE"
        if current == "IMPOSSIBLE" :
            return 1 + change
        if change == "IMPOSSIBLE" :
            return current
        return min([current, 1 + change])

def solveCase(fileIn):
    M, V = [int(x) for x in fileIn.readline().split()]
    V = bool(V)
    tree = []
    for i in range((M-1)/2) :
        G, C = [bool(int(x)) for x in fileIn.readline().split()]
        tree += [(G, C)]
    for i in range((M+1)/2) :
        I = bool(int(fileIn.readline()))
        tree += [I]
    return solve(tree, 0, M, V)

def main():
    import sys
    fileIn = open(inputFileName)
    if outputFileName == "stdout":
        fileOut = sys.stdout
    else:
        fileOut = open(outputFileName, "w")
    N = int(fileIn.readline())
    dprint("%d cases\n" % N)
    for i in range(N):
        dprint("Entering case %d\n" % (i+1))
        ans = solveCase(fileIn)
        dprint("Answer : %s\n" % ans)
        fileOut.write("Case #%d: " % (i+1))
        fileOut.write("%s\n" % ans)
    fileIn.close()
    if outputFileName != "stdout":
        fileOut.close()

if __name__== "__main__":
    main()
