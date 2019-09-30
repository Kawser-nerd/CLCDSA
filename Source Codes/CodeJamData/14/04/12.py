# Written in Python 3.3

import math
import sys

def findsol(N,n,m):

    n2 = []
    m2 = []
    for ii in range(len(n)):
        n2.append(n[ii])
        m2.append(m[ii])

    # In the game of War, where Naomi does not know Ken's
    # masses, the optimal strategy is to play from lowest
    # to highest. Ken's optimal strategy is to choose the
    # piece which is just larger than the announced mass.
    # If there is not one, he plays the lowest mass.

    n2.sort()
    m2.sort()
    sc2 = 0
    for ii in range(len(n2)):     # Loop over Naomi's pieces
        bsc = 0
        for jj in range(len(m2)): # Ken to find the best piece
            if m2[jj] > n2[ii]:
                bsc = jj
                break
        if (n2[ii] > m2[bsc]):
            sc2 += 1

        del m2[bsc]

    # In deceptive war, Naomi again should try and get rid of
    # her low weight pieces first. When they are actually lower,
    # she should say it is slightly lower than Ken's highest
    # piece. If it is higher than Ken's lowest piece, she should
    # say it is higher than Ken's highest piece.

    n.sort()
    m.sort()
    sc = 0
    for ii in range(len(n)):     # Loop over Naomi's pieces
        if m[0] > n[ii]:
            del m[len(m)-1]
        else:
            del m[0]
            sc += 1

    return str(sc) + ' ' + str(sc2)

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
    N = fidi.readline()
    N = int(N)

    # Read Naomi's blocks
    
    C = fidi.readline()
    n = convertnums(C)

    # Read Ken's blocks
    
    C = fidi.readline()
    m = convertnums(C)
    
    # Find the solution

    a = findsol(N,n,m)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



