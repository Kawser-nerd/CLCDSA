# Written in Python 3.3

import math
import sys

def findsol(X,R,C):

    if (R<C):
        tmp = R
        R = C
        C = tmp

    if (R < X):
        return 'RICHARD'
    if (X >= 7):
        return 'RICHARD'
    if (X == 1):
        return 'GABRIEL'
    if (R*C % X > 0):
        return 'RICHARD'
    if (X == 2):
        return 'GABRIEL'

    if (X == 3):
        if (C < 2):
            return 'RICHARD'
        return 'GABRIEL'

    if (X==4):
        if (C < 3):
            return 'RICHARD'  # Split into two odd sides
        return 'GABRIEL'

    if (X==5):
        if (C < 3):
            return 'RICHARD'
        if (C == 3):
            if (R == 5):
                return 'RiCHARD'  # W tile will block everything
        return 'GABRIEL'

    if (X==6):
        if (C < 3):
            return 'RICHARD'
        if (C == 3):
            return 'RICHARD'  # Asymmetric T block partitions into odd squares
        return 'GABRIEL'
        

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
    X = tmp[0]
    R = tmp[1]
    C = tmp[2]
    
    # Find the solution

    a = findsol(X,R,C)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



