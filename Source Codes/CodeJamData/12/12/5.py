#!/usr/bin/python
import os, sys, math

def solve(levelData):
    # 
    numStars = 0
    totalLevels = len(levelData)
    # Sort by two star requirement
    s = [(x[1][1], x) for x in levelData]
    twoStarsSorted = sorted(s)
    twoStarsSorted = [x[1] for x in twoStarsSorted]
    #print twoStarsSorted
    s = [(x[1][0], -1 * x[1][1], x) for x in levelData]
    oneStarsSorted = sorted(s)
    oneStarsSorted = [x[2] for x in oneStarsSorted]
    #print oneStarsSorted
    doneOne = set()
    doneTwo = set()
    oneIndex = 0
    twoIndex = 0
    numDoneTwo = 0
    steps = 0
    while (numDoneTwo < totalLevels):
        skipLoop = False
        steps += 1
        # Try to do two star one
        #print "twoIndex %d, numStars %d" % (twoIndex, numStars)
        while twoIndex < len(twoStarsSorted) and numStars >= twoStarsSorted[twoIndex][1][1] and not skipLoop:
            #print "twoIndex in loop %d" % twoIndex
            d = twoStarsSorted[twoIndex]
            if d[0] not in doneTwo:
                #print "adding %d two" % twoIndex
                # can use this
                numStars += 1 if d[0] in doneOne else 2
                doneTwo.add(d[0])
                doneOne.add(d[0])
                numDoneTwo += 1
                skipLoop = True
            twoIndex += 1
        # Nope, pick a one star one
        #print "oneIndex %d" % oneIndex
        oldOneIndex = oneIndex
        possibleIndices = []
        while oneIndex < len(oneStarsSorted) and numStars >= oneStarsSorted[oneIndex][1][0] and not skipLoop:
            #print "oneIndex in loop %d" % oneIndex
            d = oneStarsSorted[oneIndex]
            if d[0] not in doneOne:
                possibleIndices.append(oneIndex)
            oneIndex += 1
        oneIndex = oldOneIndex
        if len(possibleIndices) > 0:
            # Find the one that has the highest two-star score
            #print "possibleIndices %s" % possibleIndices
            highestTwoStar = -1
            index = -1
            for p in possibleIndices:
                d = oneStarsSorted[p]
                if (d[1][1] > highestTwoStar):
                    highestTwoStar = d[1][1]
                    index = d[0]
            #print "adding %d one" % index
            doneOne.add(index)
            numStars += 1
            skipLoop = True
        while oneIndex < len(oneStarsSorted) and oneStarsSorted[oneIndex][0] in doneOne:
            oneIndex += 1
        if not skipLoop:
            # Nope, failure
            return False

    return steps


def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        N = int(fileLines[index][:-1])
        index += 1
        levelData = []
        for i in range(N):
            caseStr = fileLines[index][:-1]
            index += 1
            nums = [int(x) for x in caseStr.split(' ')]
            A = nums[0]
            B = nums[1]
            levelData.append((i,(A,B)))
        #print caseStr
        #if (caseNum == 46):
        #    print levelData
        answer = solve(levelData)
        if answer is False:
            answer = "Too Bad"
        print "Case #%d: %s" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
