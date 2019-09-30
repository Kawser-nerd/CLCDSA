#!/usr/bin/python
import os, sys, math, itertools

def bits(x):
    return [int(y) for y in bin(x)[2:]]

def bitsToNum(x):
    return int(''.join([str(i) for i in x]), 2)

def appendZeros(bits, l):
    while len(bits) < l:
        bits = [0] + bits
    return bits

# used to generate alllotterynums.txt
def generate():
    for a in range(0,1001):
        for b in range(0,1001):
            print a, b, a&b

lines = []
def solve(a, b, k):
    if len(lines) == 0:
        for line in open('alllotterynums.txt').readlines():
            [a1, b1, k1] = [int(x) for x in line.split(' ')]
            lines.append((a1, b1, k1))
    total = 0
    for l in lines:
        if l[0] < a and l[1] < b and l[2] < k:
            total += 1
    return total

def countLessThanI(aBits, bBits, kBits, i):
    total = 0
    # let's try this, see if it's fast enough
    for ai in range(len(aBits)):
        if aBits[ai] == 1:
            thisABits = aBits[:]
            thisABits[ai] = 0
            for bi in range(len(bBits)):
                if bBits[bi] == 1:
                    thisBBits = bBits[:]
                    thisBBits[bi] = 0
                    # ok, see if we can even satisfy this
                    canSatisfy = True
                    for j in range(i+1):
                        if kBits[j] == 1:
                            if (ai >= j and thisABits[j] == 0) or (bi >= j and thisBBits[j] == 0):
                                #print "NCS: kBits %s, i %d, thisABits %s, ai %d, thisBBits %s, bi %d, j %d" % (kBits, i, thisABits, ai, thisBBits, bi, j)
                                canSatisfy = False
                                break
                        else:
                            if (ai >= j and thisABits[j] == 1) and (bi >= j and thisBBits[j] == 1):
                                #print "NCS: kBits %s, i %d, thisABits %s, ai %d, thisBBits %s, bi %d, j %d" % (kBits, i, thisABits, ai, thisBBits, bi, j)
                                canSatisfy = False
                                break
                    if canSatisfy:
                        #print "CS: kBits %s, i %d, thisABits %s, ai %d, thisBBits %s, bi %d" % (kBits, i, thisABits, ai, thisBBits, bi)
                        possibilities = 1
                        for j in range(i+1):
                            #print j, possibilities
                            # these have to be exact
                            # only choices if result is 0
                            if kBits[j] == 0:
                                aCanMove = ai < j
                                bCanMove = bi < j
                                #print j, aCanMove, bCanMove
                                if aCanMove and bCanMove:
                                    possibilities *= 3
                                elif not aCanMove:
                                    if thisABits[j] == 0:
                                        possibilities *= (2 if bCanMove else 1)
                                elif not bCanMove:
                                    if thisBBits[j] == 0:
                                        possibilities *= (2 if aCanMove else 1)


                        for j in range(i+1, len(kBits)):
                            #print j, possibilities
                            aCanMove = ai < j
                            bCanMove = bi < j
                            #print j, aCanMove, bCanMove
                            possibilities *= (2 if aCanMove else 1) * (2 if bCanMove else 1)
                        #print "adding %d" % possibilities
                        total += possibilities
    return total

def solveReal(a, b, k):
    aBits = bits(a)
    bBits = bits(b)
    kBits = bits(k)

    # normalize these
    maxLen = max(len(aBits), len(bBits), len(kBits))
    aBits = appendZeros(aBits, maxLen)
    bBits = appendZeros(bBits, maxLen)
    kBits = appendZeros(kBits, maxLen)
    #print aBits
    #print bBits
    #print kBits
    total = 0
    # OK, kBits start with a 1 somewhere
    for i in range(maxLen):
        if kBits[i] == 1:
            # count things that have a zero in this spot, and anything below it
            # (and whatever this number is above it)
            
            # see if there are any ones above this
            kBitsCopy = kBits[:]
            kBitsCopy[i] = 0
            total += countLessThanI(aBits, bBits, kBitsCopy, i)
    return total

def main(filename):
    #generate()
    #return
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (a, b, k) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        answer = solveReal(a, b, k)
        print "Case #%d: %d" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
