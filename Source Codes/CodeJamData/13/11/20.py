#!/usr/bin/python
import os, sys, math

def solve_slow(r, t):
    rings = 0
    while True:
        t -= (2*r+1)
        if t < 0:
            return rings
        rings += 1
        if t == 0:
            return rings
        r += 2
    return rings

def paint_needed(r, n):
    # for n rings, takes
    # 2*n^2 + (2*r-1)*n
    # paint
    return 2*n*n + (2*r-1)*n

def solve_fast(r, t):
    # for n rings, takes
    # 2*n^2 + (2*r-1)*n
    # paint
    n = math.floor((-1*(2*r-1) + math.sqrt((2*r-1)*(2*r-1)+4*2*t)) / 4)
    # floating point!
    n = int(n)
    if paint_needed(r, n) > t:
        return n-1
    return n
    #while True:
        #if (2*r*n + n + 2*n*(n-1)) > t:
    #    if (2*n*n + (2*r-1)*n) > t:
    #        return n-1
    #    n += 1
    
def solve_bin_search(r, t):
    # inclusive on lower, exclusive on upper
    lower_bound = 1
    upper_bound = t
    while (lower_bound + 1) < upper_bound:
        mid = int((lower_bound + upper_bound)/2)
        if paint_needed(r, mid) > t:
            upper_bound = mid
        else:
            lower_bound = mid
    return lower_bound

def main(filename):
    fileLines = open(filename, 'r').readlines()
    index = 0
    numCases = int(fileLines[index][:-1])
    index += 1
    for caseNum in range(numCases):
        (r, t) = [int(x) for x in fileLines[index][:-1].split(' ')]
        index += 1
        #answer = solve_fast(r, t)
        answer = solve_bin_search(r, t)
        #print caseStr
        print "Case #%d: %d" % (caseNum + 1, answer)

if __name__ == '__main__':
    main(sys.argv[1])
