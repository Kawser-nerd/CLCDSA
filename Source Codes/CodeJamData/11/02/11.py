#!/usr/bin/python
import sys
from sys import stderr

def Solve(combs, opos, invoke):
    print >>stderr, combs, opos, invoke

    dcombs = {}
    for c in combs:
        dcombs[c[0]+c[1]] = c[2]
        dcombs[c[1]+c[0]] = c[2]
    print >>stderr, dcombs

    dopos = {}
    for o in opos:
        dopos[o[0]] = dopos.get(o[0], "") + o[1]
        dopos[o[1]] = dopos.get(o[1], "") + o[0]
    print >>stderr, dopos


    cur = ""
    for e in invoke:
        cur += e
        combined = False
        while len(cur) >= 2:
            pair = cur[-2:]
            res = dcombs.get(pair)
            if not res:
                break
            cur = cur[:-2] + res
            combined = True
        if not combined:
            op = dopos.get(e)
            if op:
                for oo in op:
                    if oo in cur:
                        cur = ""
        print >>stderr, cur

    return "[" + ", ".join(list(cur)) + "]"


f = open(sys.argv[1])

T = int(f.readline())
for t in range(T):
    line = f.readline().split()
    ncomb = int(line[0])
    combs = line[1:ncomb+1]
    nopos = int(line[ncomb+1])
    opos = line[ncomb+2:ncomb+2+nopos]
    invoke = line[ncomb+nopos+3]
    print "Case #%d: %s" % (t+1, Solve(combs, opos, invoke))



