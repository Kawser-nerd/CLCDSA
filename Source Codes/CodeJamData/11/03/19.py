#!/usr/bin/python
import os, sys, collections

def bits(xs):
    # assumes x is >= 0, fits in 32 bits
    i = 0
    toReturn = [[0] * 32 for x in xs] 
    cur2 = 1
    while i < 32:
        for (j, x) in enumerate(xs):
            if x % 2 == 1:
                toReturn[j][i] = 1
                xs[j] -= 1
            xs[j] /= 2
        i += 1
        #cur2 *= 2
    toReturn = [x[::-1] for x in toReturn]
    return toReturn

def findBigCandy(candies):
    # First split each candy into bits
    candies.sort()
    origCandies = candies[:]
    #print candies
    candyBits = bits(candies)
    # Now, see if any position has an odd number. If so, they can never
    # be equal.
    for i in range(32):
        totalBit = sum([candyBits[x][i] for x in range(len(candyBits))])
        if totalBit % 2 == 1:
            return 'NO'
    # so we can split them up however we want!!
    return sum(origCandies[1:])

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    #print bits([0, 1, 2])
    for caseNum in range(numCases):
        numCandies = int(fileLines[index][:-1])
        index += 1
        candies = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #print candies
        answer = findBigCandy(candies)
        print "Case #%d: %s" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
