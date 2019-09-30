# Written in Python 3.3

import math
import sys

def findsol(S,Smax):
    b = 0

    c = 0
    for ii in range(len(S)):
        c += S[ii]
        if (ii - c + 1 > b):
            b = ii - c + 1

    return b

# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertnums(s):

    a = []
    ii = 0
    for jj in range(len(s)):
        if s[jj]==' ':
            if (ii < jj):
                a.append(int(s[ii:jj]))
                ii = jj + 1
                
    a.append(int(s[ii:jj]))  # No space at end

    return a

# The main code section

fidi = open('A-large.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = fidi.readline()
    jj = tmp.find(' ')
    Smax = int(tmp[0:jj])

    S = []
    for kk in range(jj+1,len(tmp)):
        try:
            S.append(int(tmp[kk]))
        except:
            print('')
        
    # Find the solution

    a = findsol(S,Smax)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



