#!/usr/bin/env python

import sys

def isrock(i,j):
    global rocks
    for r,c in rocks:
	if r==i and c==j: return True
    return False

filename=sys.argv[1]
inputfile=file(filename, 'r')
numcases=int(inputfile.readline().strip())
for case in range(1,numcases+1):
    H, W, R = map(long, inputfile.readline().strip().split())
    rocks=[]
    for k in range(R):
	r,c = map(long, inputfile.readline().strip().split())
	rocks.append((r-1,c-1))
    F = [[0]*W for i in range(H)]
    F[0][0]=1
    for i in range(1,H):
	for j in range(1,W):
	    n=0
	    if i>0 and j>1 and not isrock(i-1,j-2):
		n+=F[i-1][j-2]
	    if i>1 and j>0 and not isrock(i-2,j-1):
		n+=F[i-2][j-1]
	    F[i][j]=n
    M=F[H-1][W-1]
    print "Case #%d: %d" % (case, M % 10007)
