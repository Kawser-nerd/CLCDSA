#!/usr/bin/env python

FNAME = "B-small-attempt0.in"

PRIMDIV = 2, 3, 5, 7

class Case(object):
    def __init__(self, num):
        self.num = num

def isugly(n):
    for i in PRIMDIV:
        if n % i == 0:
            return True
    return False

def getvals(s):
    vals = []
    for i in xrange(len(s)):
        v = int(s[:i + 1])
        if not s[i + 1:]:
            prevvals = [0]
            vals.append(v)
        else:
            prevvals = getvals(s[i + 1:])          
            vals.extend([v + val for val in prevvals])
            vals.extend([v - val for val in prevvals])
    return vals
    
def getnugly(s):
    return len([val for val in getvals(s) if isugly(val)])

def parse(lines):
    cases = []
    i = 1
    while i < len(lines):
        cases.append(Case(lines[i]))
        i += 1
    return cases

if __name__ == "__main__":
    lines = file(FNAME).read().splitlines()
    answers = [getnugly(case.num) for case in parse(lines)]
    outlines = ["Case #%d: %d\n" % (i + 1, answer) for i, answer in enumerate(answers)]
    file(FNAME + ".out", "w").writelines(outlines)

