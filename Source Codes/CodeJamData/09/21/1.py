import sys
import re
import os
import time
from itertools import *
from pprint import pprint

if len(sys.argv) != 2:
    print 'specify input file'
    exit()

startTime = time.clock()

fin = open(sys.argv[1])
fout = open(os.path.splitext(sys.argv[1])[0]+'.out','w')

class Parser(object):
    def __init__(self,s):
        self.s = s
        self.i = 0
    def skipWS(self):
        while self.i < len(self.s) and self.s[self.i].isspace():
            self.i += 1
    def readItem(self):
        self.skipWS()
        result = ''
        while self.s[self.i] not in '() \t\n':
            result += self.s[self.i]
            self.i += 1
        return result
    def q(self):
        return self.s[:self.i]+'***'+self.s[self.i:]
    def readTree(self):
        self.skipWS()
        assert self.s[self.i] == '(',self.q()
        self.i += 1
        prob = self.readItem()
        prob = float(prob)
        self.skipWS()
        if self.s[self.i] == ')':
            self.i += 1
            return (prob,None,None,None)
        else:
            qual = self.readItem()
            left = self.readTree()
            right = self.readTree()
            self.skipWS()
            assert self.s[self.i] == ')',self.q()
            self.i += 1
            return (prob,qual,left,right)
        

def solve():
    L = int(next(fin))
    tree = "".join(islice(fin,L))
    tree = Parser(tree).readTree()
    #pprint(tree)
    A = int(next(fin))
    for i in range(A):
        features = set(next(fin).split()[2:])
        prob = 1
        p = tree
        while True:
            prob *= p[0]
            if p[1] is None:
                break
            if p[1] in features:
                p = p[2]
            else:
                p = p[3]
        print>>fout,"%.7f"%prob

numCases = int(next(fin))
for caseNo in range(numCases):
    print '\b'*10,100*caseNo/numCases,'%',
    print>>fout, 'Case #%s:'%(caseNo+1)
    solve()

fin.close()
fout.close()

print '\b'*10+'it took %.1fs'%(time.clock()-startTime)