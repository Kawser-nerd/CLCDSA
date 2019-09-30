#!/usr/bin/python
import os, sys

# 0 = N
# 1 = W
# 2 = E
# 3 = S
# -1 = nowhere

def moveDirection(x, y, dir):
    if dir == -1:
        return (x, y)
    elif dir == 0:
        return (x, y-1)
    elif dir == 1:
        return (x-1, y)
    elif dir == 2:
        return (x+1, y)
    else:
        return (x, y+1)

def calculateDrainDirection(map, x, y, xMax, yMax):
    # Look at the neighbors, find the lowest.
    curVal = map[y][x]
    minVal = curVal
    minDir = -1
    if y > 0:
        val = map[y-1][x]
        if (val < minVal):
            minVal = val
            minDir = 0
    if x > 0:
        val = map[y][x-1]
        if (val < minVal):
            minVal = val
            minDir = 1
    if x < xMax - 1:
        val = map[y][x+1]
        if (val < minVal):
            minVal = val
            minDir = 2
    if y < yMax - 1:
        val = map[y+1][x]
        if (val < minVal):
            minVal = val
            minDir = 3
    return minDir

# for speed??
strType = type('a')
def calculateBasins(sinkMap, map, xMax, yMax):
    nextBasin = 'a'
    for y in range(yMax):
        for x in range(xMax):
            #print sinkMap
            if (type(sinkMap[y][x]) == strType):
                continue
            # Trace a path to a basin.
            pathCoords = [(x,y)]
            coord = (x,y)
            nextCoord = sinkMap[y][x]
            while (nextCoord != coord and type(nextCoord) != strType):
                pathCoords.append(nextCoord)
                coord = nextCoord
                nextCoord = sinkMap[coord[1]][coord[0]]
            #print pathCoords
            # See if the last entry has a basin identifier yet.
            sinkCoord = pathCoords[-1]

            if (type(sinkMap[sinkCoord[1]][sinkCoord[0]]) == strType):
                basinId = sinkMap[sinkCoord[1]][sinkCoord[0]]
            else:
                # take the next one
                basinId = nextBasin
                nextBasin = chr(ord(nextBasin) + 1)
            # Set all the way along the path to this basin id.
            for basinCoord in pathCoords:
                sinkMap[basinCoord[1]][basinCoord[0]] = basinId


def main(filename):
    fileLines = open(filename, 'r').readlines()
    #print len(fileLines)
    index = 0
    numMaps = int(fileLines[index][:-1])
    index += 1
    for unused in range(numMaps):
        # Read dims of the map.
        [height, width] = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #print height, width
        # Read in the map.
        map = [[] for x in range(height)]
        for i in range(height):
            map[i] = [int(x) for x in fileLines[index][:-1].split(' ')]
            index += 1
        #print map
        sinkMap = [[None for x in range(width)] for x in range(height)]
        for y in range(height):
            for x in range(width):
                direction = calculateDrainDirection(map, x, y, width, height)
                sinkMap[y][x] = moveDirection(x, y, direction)
        #print sinkMap
        calculateBasins(sinkMap, map, width, height)
        print "Case #%d:" % (unused + 1)
        for y in range(height):
            print ' '.join(sinkMap[y])

 
if __name__ == '__main__':
    main(sys.argv[1])
