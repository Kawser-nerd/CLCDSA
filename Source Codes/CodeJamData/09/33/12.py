execfile('utils.py')

from numpy import *


def parseCases(cases,nCases):
    res = []
    for i in range(nCases):
        nPrisoners,nToRelease = map(int,cases[i*2].strip().split())
        toRelease = tuple(map(lambda y: int(y)-1,cases[i*2+1].strip().split()))
        res.append((nPrisoners,toRelease))
    return res

def process(fn):
    cases = [x.strip() for x in read1(fn)]
    nCases = int(cases[0])
    cases = parseCases(cases[1:],nCases)
##    print cases
    res = []
    for i,x in enumerate(cases):
        print i, ':', x[0],len(x[1])
        res.append(processCase(*x))
        
    res = [processCase(*x) for x in cases]
    write2(fn+".out",res)

bribe = {}

def processCase(nPrisoners,toRelease):

##    print "processCase:", nPrisoners, toRelease

    if len(toRelease) == 0:
        return 0

    key = (nPrisoners,toRelease)
    if bribe.has_key(key):
        return bribe[key]

    res = min([release(nPrisoners,x,toRelease[:i]+toRelease[i+1:]) for (i,x) in enumerate(toRelease)])
    bribe[(nPrisoners,toRelease)] = res

##    print "processCase:", nPrisoners, toRelease, "returning", res
    return res

def release(nPrisoners,released,toRelease):
##        print "release:", nPrisoners, released, toRelease
        offset = released+1
        res = (nPrisoners-1) \
               + processCase(released,tuple([x for x in toRelease if x<released])) \
               + processCase(nPrisoners-offset,tuple([x-offset for x in toRelease if x>=offset]))
##        print "release:", nPrisoners, released, toRelease, "returning", res
        return res
