#! /usr/bin/env python

import sys

filein = sys.argv[1]
fileout = sys.argv[2]
fin = file(filein)
fout = file(fileout,'w')

C = int(fin.readline())

for i in range(1,C+1):
    N = int(fin.readline())
    M = int(fin.readline())
    malts = []
    tomake = []
    for m in range(M):
        row = []
        for n in range(N):
            row.append(0)
        malts.append(row)

    for m in range(M):
        s = fin.readline().split()
        for n in range(len(s)):
            s[n] = int(s[n])
        T = s[0]
        for n in range(T):
            malts[m][s[2*n+1]-1] = 2 - s[2*n+2]

    again = 1
    impossible = 0
    while again==1 and impossible==0:
        for m in range(len(malts)):
            again = 0
            if sum(malts[m]) == 1:
                again = 1
                idx = malts[m].index(1)
                tomake.append(idx)
                malts[m] = [0]*N
                for m2 in range(M):
                    if malts[m2][idx]==1:
                        malts[m2] = [0]*N
                    elif malts[m2][idx]==2:
                        malts[m2][idx] = 0
                        if sum(malts[m2])==0:
                            impossible=1
                break
    if impossible==1:
        s = ' IMPOSSIBLE'
    else:
        s = ''
        for n in range(N):
            if n in tomake:
                s += ' 1'
            else:
                s += ' 0'
    fout.write('Case #%d:%s\n'%(i,s))

fin.close()
fout.close()
