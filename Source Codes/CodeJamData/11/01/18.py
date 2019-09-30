#!/usr/bin/python
import os, sys

def solveButtons(buttons):
    time = 0
    positions = [1, 1]
    lastUsed = [0, 0]
    for i in range(len(buttons)):
        config = buttons[i]
        bot = config[0]
        curPosition = positions[bot]
        distance = abs(curPosition - config[1])
        # Could already be walking this way
        timeToAdd = max(distance - (time - lastUsed[bot]), 0) + 1
        #print timeToAdd
        time += timeToAdd
        lastUsed[bot] = time
        positions[bot] = config[1]
    return time

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        caseStr = fileLines[index][:-1]
        index += 1
        nums = [x for x in caseStr.split(' ')]
        numButtons = int(nums[0])
        nums = nums[1:]
        buttons = zip(nums[::2], nums[1::2])
        buttons = [(0 if x == 'O' else 1, int(y)) for (x, y) in buttons]
        #print buttons
        secs = solveButtons(buttons)
        #print caseStr
        print "Case #%d: %s" % (caseNum + 1, secs)

if __name__ == '__main__':
    main(sys.argv[1])
