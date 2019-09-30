'''
Created on 22 May 2010

@author: Shahar
'''
from math import factorial

Pures = {}
Factorials = {}

def C(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    
    for iCNT in range(CNT):
        N = int(fin.readline())
        NPures = 0
        for iN in xrange(1,N) :
            NPures += FindPures(N, iN)
            #print iN
            
        text = 'Case #' + str(iCNT+1) + ': ' + str(NPures % 100003)
        print text
        fout.write(text + '\n')

def FindPures(N, I):
    if (N,I) in Pures :
        return Pures[(N,I)]
    
    if I == 1 :
        NPures = 1
    else :
        NPures = 0
        for iI in xrange(1, I) :
            n = N - I -1
            k = I - iI - 1
            if (n >= k) :
                if (n,k) in Factorials :
                    combinations = Factorials[(n,k)]
                else : 
                    combinations = (factorial(n)/(factorial(k)*factorial(n-k)))
                    Factorials[(n,k)] = combinations 
                NPures += FindPures(I, iI)* combinations
    Pures[(N,I)] = NPures
    return NPures

if __name__ == "__main__":
    #C(sys.argv[1]);
    #C('..\\test\\C-test.in');
    #C('..\\test\\C-small-attempt0.in');
    #C('..\\test\\C-small-attempt1.in');
    C('..\\test\\C-large.in');
