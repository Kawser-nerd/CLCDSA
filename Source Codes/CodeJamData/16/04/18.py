# Written in Python 3.3

import math
import sys

def findsol(K,C,S):
    if C*S < K:
        return 'IMPOSSIBLE'

    a = []
    flag = 0
    for ii in range(S):
        tmp = []
        for jj in range(C):
            x = ii*C+jj
            if (x >= K):
                x = K-1
                flag = 1
            tmp.append(x)

        # Find the coordinates in the pyramid

        tmp2 = 0
        for jj in tmp:
            tmp2 = K*tmp2+jj
        
        a.append(tmp2+1)  # Numbered from 1

        if (flag == 1):
            break

    return a

# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertnums(s):

    a = []
    ii = 0
    for jj in range(len(s)):
        if s[jj]==' ':
            if (ii < jj):
                a.append(float(s[ii:jj]))
                ii = jj + 1
                
    a.append(float(s[ii:jj]))  # No space at end

    return a

# The main code section

fidi = open('D-large.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    K = int(tmp[0])      # Number of tiles in original pattern
    C = int(tmp[1])      # Pattern complexity
    S = int(tmp[2])      # Students available
    
    # Find the solution

    a = findsol(K,C,S)

    # Show the output

    if (a[0]=='I'):
        fido.write('Case #' + str(ii)+': '+a+'\n')
        print('Case #' + str(ii)+': '+a)
    else:
        fido.write('Case #' + str(ii)+': ')
        for jj in a:
            fido.write(str(jj)+' ')
        fido.write('\n')
    
        print('Case #'+str(ii)+': ',str(a))

fidi.close()
fido.close()



