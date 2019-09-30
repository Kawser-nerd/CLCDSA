'''
Created on May 20, 2011

@author: herman
'''
from string import split
import sys

infile = open("large_input.txt","r")
outfile = open("large_output.txt","w")

trials = int(infile.readline())

for i in xrange(trials):
    nums = [int(x) for x in split(infile.readline())]
    C = nums[0]
    D = nums[1]
    Locs = []
    V = []
    for j in xrange(C):
        nums = [int(x) for x in split(infile.readline())]
        Locs.append(nums[0])
        V.append(nums[1])
    sums = [[0 for x in xrange(C)] for y in xrange(C)]
    for x in xrange(C):
        sums[x][x] = V[x]
    for j in xrange(C):
        for k in xrange(j+1,C):
            sums[j][k] = sums[j][k-1] + sums[k][k]
    #print sums
    best = -1
    for j in xrange(C):
        for k in xrange(j,C):
            vendors = sums[j][k]
            minspread = (vendors - 1.0)*D
            currspread = float(Locs[k] - Locs[j])
            maxtime = (minspread - currspread)/2.0
            #print (minspread,currspread,maxtime)
            if maxtime > best:
                best = maxtime
    s = "Case #%d: %f\n" % ((i+1),best)
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
