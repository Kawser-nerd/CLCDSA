#!/usr/bin/python
import os, sys

target = 'welcome to code jam'
#target = 'ababc'

def processCase(caseStr):
    #substrs[j][i] is the number of substrings of target[j:] that can be found
    # starting at caseStr[i].  I think. 
    substrs = [[0 for x in range(len(caseStr))] for y in range(len(target))]
    # Calculate it dynamic style!  So start from the right side...
    for i in range(len(caseStr)-1, -1, -1):
        # and calculate down, it doesn't matter.
        for j in range(len(target)):
            if caseStr[i] != target[j]:
                # Mismatch
                substrs[j][i] = 0
            elif j == len(target) - 1:
                # we're searching for a one character substring: success!
                substrs[j][i] = 1
            else:
                # In the general case, look at the line below and sum to the
                # end, not including the entry below us (since we have to 
                # advance a character)
                substrs[j][i] = sum(substrs[j+1][i+1:])
    # The substrings can start at any character, so sum the top row.
    return sum(substrs[0])

def main(filename):
    fileLines = open(filename, 'r').readlines()
    #print len(fileLines)
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        caseStr = fileLines[index][:-1]
        index += 1
        #print caseStr
        answer = processCase(caseStr)
        print "Case #%d: %04d" % (caseNum + 1, answer % 10000)
 
if __name__ == '__main__':
    main(sys.argv[1])
