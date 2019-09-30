# -*- coding: utf-8 -*-
"""
Created on Sat May 07 10:49:56 2011

@author: Shahar
"""



def B(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Case = map(float, fin.readline().split())
        D = Case[0]
        N = int(Case[1])
        NA = Case[2]
        S = []
        for iS in range(N) :
            S.append(map(float, fin.readline().split()))
        A = map(float, fin.readline().split())
        tcar = 0
        if N > 1 :
            tcar = (S[1][0] - S[0][0])*(D-S[0][1])/(S[1][1]-S[0][1])
        tcar = max(tcar, 0)
        text = 'Case #' + str(iCNT+1) + ': '
        print text
        fout.write(text + '\n')
        for a in A :
            tmine = (2*D/a)**0.5
            #print a, tcar, tmine
            text = str(max(tmine,tcar))
            print text
            fout.write(text + '\n')
            
            


if __name__ == "__main__":
    #B(sys.argv[1]);
    B#('..\\test\\B-test.in');
    B('..\\test\\B-small-attempt0.in');
    #B('..\\test\\B-small-attempt1.in');
    #B('..\\test\\B-large.in');
