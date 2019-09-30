#!/usr/bin/python
import os, sys, collections, operator

def all_perms(str):
    if len(str) <=1:
        yield str
    else:
        for perm in all_perms(str[1:]):
            for i in range(len(perm)+1):
                #nb str[0:1] works in both string and list contexts
                yield perm[:i] + str[0:1] + perm[i:]


expectedCache = {}
# l is the length of the permutation
def expected(l):
    # ...optimization based on data
    if l == 1:
        return 0
    return float(l)
    global expectedCache
    if l in expectedCache:
        return expectedCache[l]
    if l == 1:
        return 0
    c = 0
    aList = [i for i in range(1,l+1)]
    xCoeff = 0
    for perm in all_perms(aList):
        g = getExpectedOfArray(perm, True)
        #print 'perm %s: g is %f' % (perm, g)
        if g == -1:
            xCoeff += 1
        else:
            c += g
    f = 1.0 * reduce(operator.mul, range(1,l+1))
    c += f
    toReturn = (1.0 * c) / (1.0 * f - xCoeff)
    #print toReturn
    #print 'storing calc for %d: %f' % (l, toReturn)
    expectedCache[l] = toReturn
    return toReturn

def getPermutationsOfArray(a):
    ps = []
    usedIndices = set()
    for i in range(1, len(a)+1):
        if i not in usedIndices:
            size = 1
            usedIndices.add(i)
            # Trace it
            j = a[i-1]
            while j not in usedIndices:
                usedIndices.add(j)
                size += 1
                j = a[j-1]
            ps.append(size)
    return ps

def getExpectedOfArray(a, stopIfBig):
    ps = getPermutationsOfArray(a)
    if stopIfBig and len(ps) == 1:
        return -1
    #print ps
    return sum([expected(p) for p in ps])

def calcValues(m):
    for i in range(2,m+1):
        print 'expectedCache[%d] = %f' % (i, expected(i))

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        # don't care about num of integers
        index += 1
        toSort = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #print toSort
        #print getPermutationsOfArray(toSort)
        print "Case #%d: %f" % (caseNum + 1, getExpectedOfArray(toSort, False))

if __name__ == '__main__':
    #calcValues(10)
    main(sys.argv[1])
