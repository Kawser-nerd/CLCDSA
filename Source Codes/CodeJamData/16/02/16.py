# Written in Python 3.3

import math
import sys

def findsol(S):

    N = 0
    s = '+'
    for ii in range(len(S)-2,-1,-1):
        if (S[ii]!=s):
            s=S[ii]
            N += 1
            
    return N

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

fidi = open('B-large.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    S = fidi.readline()
    
    # Find the solution

    a = findsol(S)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #'+str(ii),': ',str(a))

fidi.close()
fido.close()



