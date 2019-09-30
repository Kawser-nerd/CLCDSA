#!/usr/bin/python

import sys, math

def isHappy(flavors, custLikes):
    for c in custLikes:
        happy = 0
        for f, m in c:
            if flavors[f-1] == m: happy = 1
        if not(happy): 
            return 0
    return 1

def canResolve(custLikes, numFlavors, i, k = -1, flavors=[]):
    if not(flavors): flavors = [0] * numFlavors
    for i in range(len(flavors)):
        if flavors[i] == "?":
            flavors[i] = 0

    if isHappy(flavors, custLikes): return flavors
    if i == 0: return 0

    for j in range(k+1, len(flavors)):
        
        ## Try resolving with the next one on
        p = [x for x in flavors]
        p[j] = 1
        c = canResolve(custLikes, numFlavors, i-1, j, p)
        if c: return c
    return 0

def main(numFlavors, custLikes):
    flavors=["?"] * numFlavors
    changed = 1
    mCount = 0
    while changed:
        changed = 0
        for c in [x for x in custLikes]:
            if len(c) == 1:
                f, m = c[0]
                flavors[f-1] = m
                for d in [x for x in custLikes]:
                    i = custLikes.index(d)
                    for df, dm in d:
                        if df == f:
                            if dm == m:
                                custLikes.remove(custLikes[i])
                            else:
                                d.remove((df, dm))
                                custLikes[i] = d
                                if not(d): return "IMPOSSIBLE"
                changed = 1
    if not(custLikes):
        for i in range(len(flavors)):
            if flavors[i] == "?": flavors[i] = 0
        return " ".join(["%s" % x for x in flavors])
    for i in range(flavors.count("?")):
        ## Can we do it in i?
        c = canResolve(custLikes, numFlavors, i, -1, flavors)
        if c: return " ".join(["%s" % x for x in c])
    return "IMPOSSIBLE"


def getline(fpin, types):
    args = fpin.readline().strip().split()
    for i in range(len(types)):
        args[i] = types[i](args[i])
    return args


if __name__=="__main__":
    fpin=open(sys.argv[1])
    if len(sys.argv) > 2:
        fpout = open(sys.argv[2], 'w')
    else:
        fpout = sys.stdout


    cases = int(fpin.readline().strip())
    for case in range(1,cases+1):
        (N,) = getline(fpin, [int,]) # flavors
        (M,) = getline(fpin, [int,]) # customers
        custLikes = []
        for m in range(M):
            thisLike = []
            i = [int(x) for x in fpin.readline().strip().split()]
            numIn = i[0]
            for j in range(numIn):
                thisLike.append((i[j*2+1],i[j*2+2]))
            custLikes.append(thisLike)
        fpout.write("Case #%d: %s\n" % (case, main(N, custLikes) ))

