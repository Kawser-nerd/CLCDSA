# Written in Python 3.3

import math
import sys

def findsol(P,D):

    P.sort()
    T = P[len(P)-1]

    for jj in range(1,T):
        # Determine the number of moves to get to a maximum of
        # jj in each diner's stack

        N = 0
        for kk in P:
            N += math.ceil(kk / jj) - 1
        T2 = N + jj

        if (T2 < T):
            T = T2
    
    return T

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
    D = int(fidi.readline())

    P = fidi.readline()
    P = convertnums(P)
    
    # Find the solution

    a = findsol(P,D)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



