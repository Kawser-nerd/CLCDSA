#!/usr/bin/python
import os, sys

def convertToBase(number, base):
    digits = []
    mod = base
    prevMod = 1
    # Don't care about order
    while number > 0:
        digit = (number % mod) / prevMod
        digits.append(digit)
        number = number - digit * prevMod
        prevMod = mod
        mod *= base
    if len(digits) == 0:
        digits = [0]
    return digits

def squareDigits(digits):
    return sum([x*x for x in digits])

def isHappy(number, base):
    foundNums = set()
    while True:
        digits = convertToBase(number, base)
        number = squareDigits(digits)
        if number == 1:
            return True
        if number in foundNums:
            # Got a repeat, so in a cycle
            return False
        foundNums.add(number)

def main(filename):
    fileLines = open(filename, 'r').readlines()
    #print len(fileLines)
    index = 0
    words = []
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        bases = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        i = 2
        while True:
            happy = True
            for base in bases:
                if (not isHappy(i, base)):
                    happy = False
                    break
            if happy:
                break
            i += 1
        #print bases

        print "Case #%d: %d" % (caseNum+1, i)


if __name__ == '__main__':
    main(sys.argv[1])
