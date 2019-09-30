#!/usr/bin/python
import sys

RES=10**-9

def isSufficient(x,score,others):
    """Assume that x was added to score"""
    this = x+score
    left = 1-x
    for o in others:
        if o<this: left -= (this-o) #how much needs to be added
    if left<0: return True #cannot be eliminated
    else: return False


def findMin(score,others):
    top = 1.0
    bottom = 0.0
    current = 0.5
    while top-bottom>RES:
        if isSufficient(current,score,others):
            #try making do with less
            top = current
            current = (current+bottom)/2
        else:
            bottom = current
            current = (current+top)/2
    return current
            
        


def mySol(params):
    nConts = params[0]
    scores = params[1:]
    sumScores = float(sum(scores))
    if len(scores)!=nConts: raise Exception('bad parsing')
    if len(scores)==1: return 0
    scores = [float(x)/sumScores for x in scores]


    res = []
    for i in xrange(len(scores)):
        score = scores[i]
        others = scores[:i]+scores[i+1:]
        res.append(findMin(score,others))
    
    
    resStr = ' '.join(['%10f' % (100*x) for x in res])
    return resStr




T = int(sys.stdin.readline())
for i in xrange(T):
    params = [int(x) for x in sys.stdin.readline().split()]
    print 'Case #%d: %s' % (i+1,mySol(params))



