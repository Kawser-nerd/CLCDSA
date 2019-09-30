#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def getRet(W,H,pic,posX,Dis):
    w = W-2
    h = H-2
    j,k = posX
    A = 2*j - 1
    D = 2*k - 1
    B = 2*w - D
    C = 2*h - A
    Dis2 = Dis * Dis
    I = max(Dis/B,Dis/D)
    J = max(Dis/A,Dis/C)
    retSet = set()
    zerop = False
    zeron = False
    for i in xrange(-I-1,I+2):
        x1 = i*(B+D)
        x2 = x1 + B
        x12 = x1*x1
        x22 = x2*x2
        if Dis2 < min(x12,x22):
            if i > 0:
                break
            else:
                continue
        for j in xrange(-J-1,J+2):
            y1 = j*(A+C)
            y2 = y1 + A
            y12 = y1*y1
            y22 = y2*y2
            S1 = x12 + y12
            S2 = x12 + y22
            S3 = x22 + y12
            S4 = x22 + y22
            if S1 <= Dis2:
                if x1 != 0:
                    retSet.add((cmp(x1,0),cmp(y1,0),1.0*y1/x1))
                elif y1 > 0:
                    zerop = True
                elif y1 < 0:
                    zeron = True
            if S2 <= Dis2:
                if x1 != 0:
                    retSet.add((cmp(x1,0),cmp(y2,0),1.0*y2/x1))
                elif y2 > 0:
                    zerop = True
                elif y2 < 0:
                    zeron = True
            if S3 <= Dis2:
                if x2 != 0:
                    retSet.add((cmp(x2,0),cmp(y1,0),1.0*y1/x2))
                elif y1 > 0:
                    zerop = True
                elif y1 < 0:
                    zeron = True
            if S4 <= Dis2:
                if x2 != 0:
                    retSet.add((cmp(x2,0),cmp(y2,0),1.0*y2/x2))
                elif y2 > 0:
                    zerop = True
                elif y2 < 0:
                    zeron = True
            if j>0 and min(S1,S2,S3,S4) > Dis2:
                break
    ret = len(retSet)
    if zerop == True:
        ret += 1
    if zeron == True:
        ret += 1
    return ret

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        nbs = [int(x) for x in inLines[pos].split()]
        pos += 1
        H = nbs[0]
        W = nbs[1]
        Dis = nbs[2]
        pic = []
        nb0 = 0
        for j in xrange(H):
            row = [x for x in inLines[pos+j]]
            pic.append(row)
            for k in xrange(len(row)):
                if 'X' == row[k]:
                    posX = (j,k)
                elif '#' == row[k]:
                    nb0 += 1
        pos += H
        s = 'Case #%d: ' % (i+1)
        s += str(getRet(W,H,pic,posX,Dis))
        print s
