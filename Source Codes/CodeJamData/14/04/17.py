inputFile = open('D-large.in', 'r')
lines = inputFile.readlines()
inputFile.close()

outputFile = open('D-large.out', 'w')

numTests = int(lines[0])

def scoreWar(naomiNums, kenNums):
    naomiInd = 0
    kenInd = 0
    while naomiInd < len(naomiNums):
        naomiPlay = naomiNums[naomiInd]
        while kenInd < len(kenNums) and kenNums[kenInd] < naomiPlay:
            kenInd += 1
        if kenInd == len(kenNums):
            break
        naomiInd += 1
        kenInd += 1
    return len(naomiNums) - naomiInd

def scoreDeceit(naomiNums, kenNums):
    naomiInd = 0
    kenInd = 0
    while kenInd < len(kenNums):
        kenPlay = kenNums[kenInd]
        while naomiInd < len(naomiNums) and naomiNums[naomiInd] < kenPlay:
            naomiInd += 1
        if naomiInd == len(naomiNums):
            break
        naomiInd += 1
        kenInd += 1
    return kenInd

for i in range(1, numTests+1):
    naomiNums = map(lambda x: float(x), lines[3*i-1].split())
    kenNums = map(lambda x: float(x), lines[3*i].split())
    naomiNums.sort()
    kenNums.sort()
    deceitScore = scoreDeceit(naomiNums, kenNums)
    warScore = scoreWar(naomiNums, kenNums)
    outputFile.write('Case #'+str(i)+': ' + str(deceitScore) + ' ' + str(warScore) + '\n')

outputFile.close()
