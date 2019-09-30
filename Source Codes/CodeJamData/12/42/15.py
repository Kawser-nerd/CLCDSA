"""Problem b: mats"""
# Just try greedy.  Given constraints, might be good enough

import unittest
import operator
import sys

class Student(object):
    def __init__(self, index, reach):
        self.r = reach
        self.x = None
        self.y = None
        self.done = False
        self.i = index
    def getCenterString(self):
        if self.x == 0:
            xc = 0
        else:
            xc = self.x + self.r
        if self.y == 0:
            yc = 0
        else:
            yc = self.y + self.r
        return "%r %r" % (xc, yc)
    def __repr__(self):
        return "Student(%r,%r,(%r,%r),%r)" % (self.i, self.r, self.x,self.y,self.done)

def tryXfit(s, x, y, w, l):
    # x and y are previous contraints or zero
    if (x != 0):
        if (x + s.r) > w:
            return False
    if (y != 0):
        if (y + s.r) > l:
            return False
    return True

def solveIt(width, length, reaches):
    s = map(lambda x: Student(x[0], x[1]), zip(range(len(reaches)), reaches))
    def cmpByReach(x,y):
        return cmp(x.r, y.r)
    s.sort(cmp=cmpByReach)
    numDone=0
    x=0
    y=0
    nextY=0
    lineChangeAt = -1
    while numDone < len(reaches):
        foundOne=False
        for i in xrange(len(s)):
            t = s[i]
            if t.done:
                continue
            b = tryXfit(t, x, y, width, length)
            if b:
                #print "Assigning for %r" % t.i
                t.done = True
                t.x = x  # upper left
                t.y = y
                if x == 0:
                    x += t.r
                else:
                    x += (2*t.r)
                if y == 0:
                    nextY = max(nextY, (y + t.r))
                else:
                    nextY = max(nextY, (y + 2*t.r))
                numDone += 1
                foundOne = True
                break
        if foundOne:
            continue
        # change lines
        x = 0
        y = nextY
        if numDone == lineChangeAt:
            print "No progress"
            assert(False)
        lineChangeAt=numDone
    def cmpByIndex(x,y):
        return cmp(x.i, y.i)
    s.sort(cmp=cmpByIndex)
    #print locals()
    z = map(lambda x: x.getCenterString(), s)
    return " ".join(z)

def solveProblems(filename):
    f = open(filename, "r")
    l = f.readlines()
    f.close()
    l = map(lambda x: x[:-1], l)
    numCases = int(l[0])
    l = l[1:]
    for i in xrange(numCases):
        print >> sys.stderr, "Computing case %d" % (i + 1)
        (numStudents, width, length) = map(int, l[0].split())[:3]
        reaches = map(int, l[1].split())[:numStudents]
        l = l[2:]
        print "Case #%d: %s" % ((i + 1),solveIt(width, length, reaches))

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
