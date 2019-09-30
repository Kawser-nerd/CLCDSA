# -*- coding: utf-8 -*-
"""
Created on Sat May 07 11:45:04 2011

@author: Shahar
"""

from operator import add

def MaxScore(i, j, ini, inj, Case) :
    #print i,j,ini,inj,Case
    if (i,j,ini,inj) in Case['max'] :
        return Case['max'][(i,j,ini,inj)]
    if i == len(Case['A']) or j == len(Case['B']) :
        return 0
    if ini ==  Case['a'][i]:
        return MaxScore(i+1, j, 0, inj, Case)
    if inj == Case['b'][j] :
        return MaxScore(i, j+1, ini, 0, Case)
        
    if Case['A'][i] == Case['B'][j] :
        avail = min(Case['a'][i]-ini, Case['b'][j]-inj)
        currMax =  avail + MaxScore(i, j, ini+avail, inj+avail, Case)
    else :
        currMax =  max(MaxScore(i+1, j, 0, inj, Case), MaxScore(i, j+1, ini, 0, Case))
    
    Case['max'][(i,j,ini,inj)] = currMax
    return currMax
        
    
def C(inpfile):
    fin = open(inpfile, 'r')
    fout = open(inpfile+'.out', 'w')
    CNT = int(fin.readline())
    for iCNT in xrange(CNT):
        Case = {}
        Case0 = map(int, fin.readline().split())
        N = Case0[0]
        M = Case0[1]
        Case1 = map(int, fin.readline().split())
        Case['a'] = Case1[::2]
        Case['A'] = Case1[1::2]
        Case2 = map(int, fin.readline().split())
        Case['b'] = Case2[::2]
        Case['B'] = Case2[1::2]
        Case['max'] = {}
        
        text = 'Case #' + str(iCNT+1) + ': ' + str(MaxScore(0,0,0,0,Case))
        print text
        fout.write(text + '\n')
        
if __name__ == "__main__":
    #C(sys.argv[1]);
    #C('..\\test\\C-test.in');
    #C('..\\test\\C-small-attempt0.in');
    #C('..\\test\\C-small-attempt1.in');
    C('..\\test\\C-large.in');
