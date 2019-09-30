#!/usr/bin/python
import os, sys, math, itertools

# assumes they have the same signature
def findDistance(cs1, cs2):
    nums1 = [x[1] for x in cs1]
    nums2 = [x[1] for x in cs2]
    return sum([abs(x[1]-x[0]) for x in zip(nums1, nums2)])

def solve(strings):
    compressedStrings = []
    for s in strings:
        cs = []
        lastChar = s[0]
        lastNum = 1
        index = 1
        while index < len(s):
            if s[index] != lastChar:
                cs.append((lastChar, lastNum))
                lastChar = s[index]
                lastNum = 1
            else:
                lastNum += 1
            index += 1
        cs.append((lastChar, lastNum))
        compressedStrings.append(cs)
    #print compressedStrings
    # group them by their "signature"
    sigMap = {}
    for cs in compressedStrings:
        sig = tuple(x[0] for x in cs)
        if sig not in sigMap:
            sigMap[sig] = []
        sigMap[sig].append(cs)

    #print sigMap
    minLength = 100000
    # now solve it
    if len(sigMap.keys()) > 1:
        return None
    # this only happens once
    for sig in sigMap:
        distance = 0
        candidates = sigMap[sig]
        for charIndex in range(len(candidates[0])):
            lengths = [x[charIndex][1] for x in candidates]
            # try getting to each one, only O(n^2)
            minCharDistance = 100000
            for target in lengths:
                thisCharDistance = 0
                for source in lengths:
                    thisCharDistance += abs(target-source)
                minCharDistance = min(minCharDistance, thisCharDistance)
            distance += minCharDistance
        # TODO - have to be more clever
        #for c2 in candidates[1:]:
        #    distance += findDistance(candidates[0], c2)
        return distance

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        n = int(fileLines[index][:-1])
        index += 1
        strings = []
        for i in range(n):
            strings.append(fileLines[index+i][:-1])
        index += n
        answer = solve(strings)
        #print caseStr
        print "Case #%d: %s" % (caseNum + 1, str(answer) if (answer is not None) else 'Fegla Won')

if __name__ == '__main__':
    main(sys.argv[1])
