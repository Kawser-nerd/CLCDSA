filename = "B-large.in"
outputname = filename + "out.txt"

inFile = open(filename, 'r')
outFile = open(outputname, 'w')

numCases = int(inFile.readline())

def getTime(fullGapList, ttb, numStations):
    currTime = 0
    counter = 0
    while currTime < ttb and counter < len(fullGapList):
        currTime += fullGapList[counter]*2
        counter += 1
    if counter == len(fullGapList):
        return sum(fullGapList)*2
    newGapList = fullGapList[counter:]
    if currTime != ttb:
        newGapList += [(currTime - ttb)/2]
    newGapList.sort()
    newGapList.reverse()
    stations = newGapList[0:numStations]
    return sum(fullGapList)*2 - sum(stations)


for i in range(numCases):
    print i
    nextLine = inFile.readline().split()
    numStations = int(nextLine[0])
    timeToBuild = int(nextLine[1])
    numStars = int(nextLine[2])
    numGaps = int(nextLine[3])
    gapList = []
    for j in range(numGaps):
        gapList += [int(nextLine[4+j])]
    fullGapList = []
    while len(fullGapList) < numStars:
        fullGapList += gapList
    fullGapList = fullGapList[0:numStars]
    
    answer = getTime(fullGapList, timeToBuild, numStations)
    
    outFile.write("Case #" + str(i+1) + ": " + str(answer) + "\n")

inFile.close()
outFile.close()




def oneStation(fullGapList, pos, ttb):
    priorTime = sum(fullGapList[0:pos])*2
    afterTime = sum(fullGapList[pos+1:])*2
    if priorTime > ttb:
        return priorTime + fullGapList[pos] + afterTime
    elif priorTime + 2*fullGapList[pos] < ttb:
        return priorTime + 2*fullGapList[pos] + afterTime
    else:
        return priorTime + (ttb-priorTime)/2 + fullGapList[pos] + afterTime

def twoStation(fullGapList, pos1, pos2, ttb):
    priorTime = sum(fullGapList[0:pos1])*2
    if priorTime > ttb:
        afterBoost = priorTime + fullGapList[pos1]
    elif priorTime + 2*fullGapList[pos1] < ttb:
        afterBoost = priorTime + 2*fullGapList[pos1]
    else:
        afterBoost = priorTime + (ttb-priorTime)/2 + fullGapList[pos1]

    priorTime = afterBoost + sum(fullGapList[pos1+1:pos2])*2
    if priorTime > ttb:
        afterBoost = priorTime + fullGapList[pos2]
    elif priorTime + 2*fullGapList[pos2] < ttb:
        afterBoost = priorTime + 2*fullGapList[pos2]
    else:
        afterBoost = priorTime + (ttb-priorTime)/2 + fullGapList[pos2]
    return afterBoost + sum(fullGapList[pos2+1:])*2
