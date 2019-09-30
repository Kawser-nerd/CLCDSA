import itertools
import fileinput

import psyco
psyco.full()

class bipG(object):
    def __init__(self,numVerts):
        self.numVerts = numVerts
        self.rooms = set((frozenset(range(numVerts)),))
    

def checkSol(g,vertColors,numColors):
    for r in g.rooms:
        seenColors = set()
        for v in r:
            seenColors.add(vertColors[v])
        if len(seenColors) < numColors:
            return False
    return True
        

def solveGraph(g):
    for numColors in range(min(len(x) for x in g.rooms),0,-1):
        for possibleColoring in itertools.product(range(numColors),repeat=g.numVerts):
            if checkSol(g,possibleColoring,numColors):
                return numColors,possibleColoring

def inPartAOf(v,u,w):
    if u < v:
        return inPartAOf(u,v,w)
    if (v < w) and (w < u):
        #print "in:",w,v,u
        return True
    #print "out:",w,v,u
    return False

def buildGraph(g,inputPairs):
    for u,v in inputPairs:
        for r in g.rooms:
            if u in r and v in r:
                g.rooms.remove(r)
                leftPart = set()
                rightPart = set()
                for w in r:
                    if w == v or w == u:
                        leftPart.add(w)
                        rightPart.add(w)
                    elif inPartAOf(v,u,w):
                        leftPart.add(w)
                    else:
                        rightPart.add(w)
                g.rooms.add(frozenset(leftPart))
                g.rooms.add(frozenset(rightPart))
                break
    #print "Rooms:",g.rooms
    return g

def runAlgo(i,it):
    N,M = [int(x) for x in it.next().split()]
    g = bipG(N)
    us = [int(x)-1 for x in it.next().split()]
    vs = [int(x)-1 for x in it.next().split()]
    g = buildGraph(g,zip(us,vs))
    assert len(g.rooms) == M + 1
    num,colors = solveGraph(g)
    print "Case #%d: %d" % (i+1,num)
    for c in colors:
        print c+1,
    print ""


def main():
    it = fileinput.input()
    numCases = int(it.next())
    for i in range(numCases):
        runAlgo(i,it)

main()
