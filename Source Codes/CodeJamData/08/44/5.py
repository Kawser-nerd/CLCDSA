def genPerms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in genPerms(str[1:]):
            for i in range(len(perm)+1):
                yield perm[:i] + str[0:1] + perm[i:]

def calcRLC(string):
    RLC = 1
    prev = string[0]
    for i in range(1, len(string)):
        if prev != string[i]:
            RLC = RLC + 1
        prev = string[i]
    return RLC
    

inFile = open("D-small-attempt0.in", "r")
outFile = open("D-small-out.out", "w")

cases = int(inFile.readline())

for caseNum in range(1, cases+1):
    k = int(inFile.readline())
    string = inFile.readline().rstrip()

    minRLC = len(string)
    
    for perm in genPerms(range(k)):
        permutedString = ""
        for i in range(0, len(string), k):
            for j in perm:
                permutedString += string[i + j]
        RLC = calcRLC(permutedString)
        if RLC < minRLC:
            minRLC = RLC

##    print minRLC

    outputString = "Case #" + str(caseNum) + ": " + str(minRLC) + "\n"
    print outputString.rstrip()

    outFile.write(outputString)



inFile.close()
outFile.close()
