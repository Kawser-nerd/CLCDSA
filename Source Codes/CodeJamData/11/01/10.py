#!/usr/bin/python
import sys
from sys import stderr

class Target:
    def __init__(self):
        self.o = 0
        self.b = 0
    def __repr__(self):
        return "<%d,%d>" % (self.o, self.b)

def Solve(arg):
    print >> stderr, arg
    targets = []
    posO = 0
    posB = 0
    for a in arg:
        targets.append(Target())
    for i in range(len(arg), 0, -1):
        if arg[i-1][0] == 'O':
            posO = arg[i-1][1]
        else:
            posB = arg[i-1][1]
        targets[i-1].o = posO
        targets[i-1].b = posB
    print >> stderr, "Targets", targets

    posO = 1
    posB = 1
    time = 0
    for i in range(len(arg)):
        if arg[i][0] == 'O':
            adv = abs(posO - arg[i][1]) + 1
            posO = arg[i][1]
            needB = targets[i].b - posB
            if abs(needB) <= adv:
                posB = targets[i].b
            elif needB < 0:
                posB -= adv
            else:
                posB += adv
        else:
            adv = abs(posB - arg[i][1]) + 1
            posB = arg[i][1]
            needO = targets[i].o - posO
            if abs(needO) <= adv:
                posO = targets[i].o
            elif needO < 0:
                posO -= adv
            else:
                posO += adv
        time += adv
        print >> stderr, i, time
    return time

f = open(sys.argv[1])

T = int(f.readline())
for t in range(T):
    line = f.readline().split()
    arg = zip(line[1::2], map(int,line[2::2]))
    print "Case #%d: %d" % (t+1, Solve(arg))
