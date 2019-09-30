# -*- coding: utf-8 -*-
"""
Created on Sat May 07 10:07:30 2011

@author: Shahar
"""
import string


def FindAncestorsDiamond(i, Parents, Ancestors) :
    PofI = Parents[i]
    anI = PofI
    for p in PofI :
        if p not in Ancestors :
            if FindAncestorsDiamond(p, Parents, Ancestors) :
                return True
        if len(anI & Ancestors[p]) > 0 :
            return True
        anI = anI | Ancestors[p]
    Ancestors[i] = anI
    return False

        
        
            

def A(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Parents = []
        N = int(fin.readline())
        for iC in xrange(1,N+1) :
            Parents.append(set(map(lambda x:int(x)-1, fin.readline().split()[1:])))
        Ancestors = {}
        #print Parents
        
        Answer = False
        for iC in xrange(N) :
            if FindAncestorsDiamond(iC, Parents, Ancestors) :
                Answer = True
                break   
            
        text = 'Case #' + str(iCNT+1) + ': '  + (Answer and 'Yes' or 'No')
        print text
        fout.write(text + '\n')

if __name__ == "__main__":
    #A(sys.argv[1]);
    #A('..\\test\\A-test.in');
    #A('..\\test\\A-small-attempt0.in');
    #A('..\\test\\A-small-attempt1.in');
    A('..\\test\\A-large.in');
