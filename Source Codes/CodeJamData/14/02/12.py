# Written in Python 3.3

import math
import sys

def findsol(C,F,X):

    t = 0.0
    tmax = X / 2

    N = 0
    while 1:
        t += C / (2 + N * F)
        if (t  > tmax):
            return str(tmax)

        # Have time to buy another farm, so do it

        N += 1

        # What time if buying no more cookie farms?
        
        t2 = t + X / (2 + N * F)
        if (t2 < tmax):
            tmax = t2
    
    return b

# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertreals(s):

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

fidi = open('B-large.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    R = fidi.readline()
    R = convertreals(R)

    C = R[0]
    F = R[1]
    X = R[2]
    
    # Find the solution

    a = findsol(C,F,X)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



