#!/usr/bin/python
import os, sys, math

def sortCars(cars):
    s = [(c[2], c) for c in cars]
    s = sorted(s)
    return [c[1] for c in s]

#def isSortedBySpeed(cars):
#    if len(cars) < 2:
#        return True
#    speed = cars[0]
#    for i in range(1, len(cars)):
#        if cars[i][1] < speed:
#            return False
#        speed = cars[i][1]
#    return True

def firstCol(cars):
    if len(cars) < 2:
        return None
    colTime = None
    for i in range(len(cars) - 1):
        c1 = cars[i]
        c2 = cars[i+1]
        # see if colliding now
        if (abs(c1[2] - c2[2]) < 5):
            return 0
        if (c1[1] > c2[1]):
            # behind car is faster
            t = float(c2[2] - c1[2] - 5) / (c1[1] - c2[1])
            if colTime is None or t < colTime:
                colTime = t
    return colTime

def advanceCars(cars, time):
    return [(c[0], c[1], c[2] + time * c[1]) for c in cars]


def isSpotFor(c, cars):
    pos = c[2]
    for car in cars:
        if abs(car[2] - pos) < 5:
            return False
    return True

def processSwitches(cars1, cars2):
    indicesToLose = []
    for i in range(len(cars1)-1):
        c1 = cars1[i]
        c2 = cars1[i+1]
        if (abs(c1[2]-c2[2]) <= 5.0):
            # cars are about to collide!
            # only bad if c1 speed strictly > c2 speed
            #print "GOTTA SWITCH i is %d" % i
            if c1[1] > c2[1]:
                # ok, can c1 switch lanes?
                if isSpotFor(c1, cars2):
                    cars2.append(c1)
                    indicesToLose.append(i)
                elif isSpotFor(c2, cars2):
                    cars2.append(c2)
                    indicesToLose.append(i+1)
                else:
                    return False
    # remove indices
    # argh
    offset = 0
    for i in range(len(indicesToLose)):
        index = indicesToLose[i] - offset
        #print "index %d, cars %s" % (index, cars1)
        cars1.pop(index)
        #print "now cars %s" % cars1
        offset += 1
    return True


def solve(cars):
    time = 0
    leftCars = sortCars([c for c in cars if c[0] == 0])
    rightCars = sortCars([c for c in cars if c[0] == 1])
    #print leftCars
    #print rightCars
    lastTimes = []
    NUM_TIMES = 5
    while True:
        #print "time is %f" % time
        lastTimes.append(time)
        if len(lastTimes) > NUM_TIMES:
            earlyTime = lastTimes.pop(0)
            if earlyTime == time:
                return time
        leftCars = sortCars(leftCars)
        rightCars = sortCars(rightCars)
        #print leftCars
        #print rightCars
        firstCollisionLeft = firstCol(leftCars)
        firstCollisionRight = firstCol(rightCars)
        #print firstCollisionLeft
        #print firstCollisionRight
        if firstCollisionLeft is None and firstCollisionRight is None:
            # all is well!
            return False
        # see when first collision
        doLeft = (firstCollisionRight is None) or ((firstCollisionLeft is not None) and (firstCollisionLeft < firstCollisionRight))
        if doLeft:
            firstCollision = firstCollisionLeft
        else:
            firstCollision = firstCollisionRight
        # Advance all cars to this time
        time += firstCollision
        leftCars = advanceCars(leftCars, firstCollision)
        rightCars = advanceCars(rightCars, firstCollision)
        #print "after advance:"
        #print leftCars
        #print rightCars
        # See if we can switch
        # argh, should be array of two
        badLane = leftCars if doLeft else rightCars
        goodLane = rightCars if doLeft else leftCars
        # See if we can switch
        isOK = processSwitches(leftCars, rightCars)
        #print leftCars
        #print rightCars
        if not isOK:
            return time
        isOK = processSwitches(rightCars, leftCars)
        #print leftCars
        #print rightCars
        if not isOK:
            return time

    return 100


def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        N = int(fileLines[index][:-1])
        index += 1
        cars = []
        for i in range(N):
            caseStr = fileLines[index][:-1]
            index += 1
            data = caseStr.split(' ')
            lOrR = 0 if data[0] == "L" else 1
            speed = int(data[1])
            pos = int(data[2])
            cars.append((lOrR, speed, pos))
        coll = solve(cars)
        if coll is False:
            coll = "Possible"
        print "Case #%d: %s" % (caseNum + 1, coll)

if __name__ == '__main__':
    main(sys.argv[1])
