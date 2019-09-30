"""Google code jam 2012 problem A.  Vines"""


import unittest
import operator
import sys
import math

def solveIt(vines, D):
    # Vines are distance, length
    v0 = vines[0]
    initialState = (v0[0],v0[0])
    if v0[0] > v0[1]:
        return "NO"
    numVines = len(vines)
    toSearch = {}
    best = list([0] * numVines)
    best[0] = v0[0]
    toSearch[0] = True
    while toSearch != {}:
        l = toSearch.keys()
        l.sort()
        i = l[0]
        del toSearch[i]
        x = vines[i][0]
        b = best[i]
        if (b + x) >= D:
            return "YES"
        #print locals()
        for j in xrange(numVines):
            if i == j:
                continue
            if vines[j][0] <= x:
                continue
            delta = vines[j][0] - x
            if delta > b:
                continue
            y = delta # don't use pythagorean
            y = min(delta, vines[j][1])
            if y > best[j]:
                #print "Adding"
                best[j] = y
                toSearch[j] = True
    return "NO"
    print locals()
    return "Maybe"

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        numVines = int(l[0])
        vines = l[1:(1+numVines)]
        l = l[(1+numVines):]
        D = int(l[0])
        l = l[1:]
        vines = map(lambda x: x.split()[:2], vines)
        vines = map(lambda x: map(int, x), vines)
        print "Case #%d: %s" % ((i + 1),solveIt(vines, D))

import getopt
def main():
    try:
        opts, args = getopt.gnu_getopt(sys.argv[1:], "th", ["test", "help"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        #usage()
        sys.exit(2)
    for o, a in opts:
        if o in {"-t" : True, "--test" : True}:
            sys.argv = ["foo"] #+ args
            unittest.main()
            return
        elif o in {"-h" : True, "--help" : True}:
            #usage()
            sys.exit()
        else:
            assert False, "unhandled option"
    solveProblems(args[0])
 
if __name__ == "__main__":
    main()

# In:  
# Out: 
