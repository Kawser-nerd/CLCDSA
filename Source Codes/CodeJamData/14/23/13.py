#!/usr/bin/python
import os, sys, math, itertools

def canFlySingle(flights, c1, c2):
    return ((c1, c2) in flights or (c2, c1) in flights)

# returns the new curPathFromStart
def canFlyPath(flights, path, c2):
    # can backtrack!
    for p in path[::-1]:
        if canFlySingle(flights, p, c2):
            return path[:path.index(p)+1]
    return None

def findCityOrdering(curPath, curPathFromStart, citiesSorted, flights):
    path = curPath[:]
    pathFromStart = curPathFromStart[:]
    #rint path
    if len(path) == len(citiesSorted):
        #rint 'done??'
        return path
    for c in citiesSorted:
        if c not in path:
            # see if we can get here
            #print 'examining %d' % c
            canFly = len(path) == 0
            oldPathFromStart = pathFromStart[:]
            if not canFly:
                newCurPath = canFlyPath(flights, pathFromStart, c)
                if newCurPath is not None:
                    canFly = True
                    pathFromStart = newCurPath
            if canFly:
                path.append(c)
                pathFromStart.append(c)
                fullPath = findCityOrdering(path, pathFromStart, citiesSorted, flights)
                if fullPath is not None:
                    return fullPath
                path = path[:-1]
                pathFromStart = oldPathFromStart
    #rint 'nope'
    return None

def solve(zipCodes, flights):
    # just try them all
    # start at smallest
    citiesSorted = [x[1] for x in sorted([(zipCodes[i], i) for i in range(len(zipCodes))])]
    ordering = findCityOrdering([], [], citiesSorted, flights)
    #print ordering
    s = ''
    for cityIndex in ordering:
        s += str(zipCodes[cityIndex])
    return s


def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        [n, m] = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        zipCodes = []
        for i in range(n):
            zipCodes.append(int(fileLines[index+i][:-1]))
        index += n
        flights = []
        for i in range(m):
            flights.append(tuple(int(x)-1 for x in fileLines[index+i].strip().split(' ')))
        index += m
        #rint flights
        answer = solve(zipCodes, flights)
        #print caseStr
        print "Case #%d: %s" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
