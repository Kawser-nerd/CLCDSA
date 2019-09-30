#!/usr/bin/python
import os, sys, math

def getCaveData(mountain):
    # find the caves
    cavePositions = {}
    for (y,r) in enumerate(mountain):
        for (x,c) in enumerate(r):
            if c >= '0' and c <= '9':
                cavePositions[ord(c)-ord('0')] = (x,y)
    #print cavePositions
    numCaves = len(cavePositions)
    # d = 0 = up
    # d = 1 = down
    # d = 2 = left
    # d = 3 = right
    def moveOneSquare(square, d):
        (x, y) = square
        if (d == 0):
            testPos = (x,y-1)
        elif (d == 1):
            testPos = (x,y+1)
        elif (d == 2):
            testPos = (x-1,y)
        elif (d == 3):
            testPos = (x+1,y)
        if mountain[testPos[1]][testPos[0]] == '#':
            return square
        return testPos
    def moveDirection(sqs, d, keepOld):
        if keepOld:
            newSquares = set(sqs)
        else:
            newSquares = set()
        for s in sqs:
            newSquares.add(moveOneSquare(s, d))
        return newSquares

    caveData = []
    # ignore edges
    mountainWidth = len(mountain[0])-2
    for cave in range(numCaves):
        cache = {}
        cavePos = cavePositions[cave]
        # find how many squares we can get to
        squares = set([cavePos])
        lastLen = len(squares)
        squares = moveDirection(squares,0, True)
        squares = moveDirection(squares,2, True)
        squares = moveDirection(squares,3, True)
        while (lastLen != len(squares)):
            lastLen = len(squares)
            squares = moveDirection(squares,0, True)
            squares = moveDirection(squares,2, True)
            squares = moveDirection(squares,3, True)
        reachableSquares = frozenset(squares)
        numReachableSquares = len(reachableSquares)
        # OK, see if we can do this
        isLucky = False
        def isSolved(sq):
            return len(sq) == 1 and cavePos in sq
        def canSolveAfterMovingDown(sq, trying):
            downSquares = moveDirection(sq, 1, False)
            return isSolvable(downSquares, trying)
        def isSolvable(sq, trying):
            frozenSq = frozenset(sq)
            #print sq
            if frozenSq in cache:
                return cache[frozenSq]
            if isSolved(sq):
                cache[frozenSq] = True
                return True
            for s in sq:
                # too far down
                if s[1] > cavePos[1]:
                    cache[frozenSq] = False
                    return False
                if s[1] == cavePos[1]:
                    if s[0] < cavePos[0]:
                        for x in range(s[0]+1, cavePos[0]):
                            if mountain[s[1]][x] == '#':
                                cache[frozenSq] = False
                                return False
                    elif s[0] > cavePos[0]:
                        for x in range(cavePos[0]+1, s[0]):
                            if mountain[s[1]][x] == '#':
                                cache[frozenSq] = False
                                return False
            # Gather up, both ways since I'm unsure
            if frozenSq in trying:
                return False
            #print frozenSq
            trying.add(frozenSq)
            leftSquares = set(sq)
            #print 'first: %s' % leftSquares
            if (canSolveAfterMovingDown(leftSquares, trying)):
                cache[frozenSq] = True
                if frozenSq in trying:
                    trying.remove(frozenSq)
                return True
            #print 'before left loop 0'
            for i in range(mountainWidth):
                newLeftSquares = moveDirection(leftSquares, 2, False)
                if newLeftSquares == leftSquares:
                    break
                #print newLeftSquares
                if (isSolved(newLeftSquares)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                if (canSolveAfterMovingDown(newLeftSquares, trying)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                leftSquares = newLeftSquares
            #print 'before right loop 0'
            for i in range(mountainWidth):
                newLeftSquares = moveDirection(leftSquares, 3, False)
                if newLeftSquares == leftSquares:
                    break
                if (isSolved(newLeftSquares)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                if (canSolveAfterMovingDown(newLeftSquares, trying)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                leftSquares = newLeftSquares
            #print 'before left loop 1'
            for i in range(mountainWidth):
                newLeftSquares = moveDirection(leftSquares, 2, False)
                if newLeftSquares == leftSquares:
                    break
                if (isSolved(newLeftSquares)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                if (canSolveAfterMovingDown(newLeftSquares, trying)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                leftSquares = newLeftSquares
            #print 'before right loop 1'
            for i in range(mountainWidth):
                newLeftSquares = moveDirection(leftSquares, 3, False)
                if newLeftSquares == leftSquares:
                    break
                if (isSolved(newLeftSquares)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                if (canSolveAfterMovingDown(newLeftSquares, trying)):
                    cache[frozenSq] = True
                    if frozenSq in trying:
                        trying.remove(frozenSq)
                    return True
                leftSquares = newLeftSquares

            cache[frozenSq] = False
            if frozenSq in trying:
                trying.remove(frozenSq)
            return False

        #print 'toplevel'
        t = set()
        isLucky = isSolvable(set(reachableSquares), t)

        caveData.append((numReachableSquares, isLucky))
    return caveData


def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        R, C = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        mountain = []
        for i in range(R):
            mountain.append(fileLines[index][:-1])
            index += 1
        #print mountain
        #positions = placeStudents(W, L, reaches)
        print 'Case #%d:' % (caseNum + 1)
        caveData = getCaveData(mountain)
        for i in range(len(caveData)):
            print "%d: %d %s" % (i, caveData[i][0], 'Lucky' if caveData[i][1] else 'Unlucky')

if __name__ == '__main__':
    main(sys.argv[1])
