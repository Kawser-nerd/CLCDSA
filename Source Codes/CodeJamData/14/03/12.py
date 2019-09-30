# Written in Python 3.3

import math
import sys

def board2str(brd):
    if len(brd)==0:
        a = 'Impossible'
        return a
    
    a = ''
    for ii in range(len(brd)):
        for jj in range(len(brd[ii])):
            if brd[ii][jj]==1:
                a += '*'
            if brd[ii][jj]==0:
                a += '.'
            if brd[ii][jj]==-1:
                a += 'c'
        if (ii < len(brd)-1):
            a += '\n'
    return a

def clearrect(brd,nr,nc,R,C):

    if (nr <= R) and (nc <= C):
        for ii in range(nr):
            for jj in range(nc):
                brd[ii][jj] = 0
    else:
        for ii in range(nc):
            for jj in range(nr):
                brd[ii][jj] = 0
                
    brd[0][0] = -1
    return

def findsol(R,C,M):

    N = R * C - M

    # Initialise the board

    brd = []
    for ii in range(R):
        brd.append([]);
        for jj in range(C):
            brd[ii].append(1)
    brd[0][0] = -1

    if (N==1):  # All but one mines
        return brd

    if (M==0):  # No mines
        clearrect(brd,R,C,R,C)
        return brd

    if (R==1) or (C==1):
        clearrect(brd,N,1,R,C)
        return brd

    # For each of the areas, try to fit an (x,y) square + 2

    x = 2
    while (x <= R) or (x <= C):
        z = N % x
        y = int(N / x)
  
        if (z == 0) and (y > 1):
            if ((x <= R) and (y <= C)) or ((x <= C) and (y <= R)):
                clearrect(brd,x,y,R,C)
                return brd
        
        if (z > 1) and (y > 1):
            if ((x <= R) and (y+1 <= C)):
                clearrect(brd,x,y,R,C)
                clearrect(brd,z,y+1,R,C)
                return brd
            if (y+1 <= R) and (x <= C):
                clearrect(brd,y,x,R,C)
                clearrect(brd,y+1,z,R,C)
                return brd

        x = x + 1

    # Fit a triangle in the far corner

    if (R < C):
        tmp = int((R-1)*(R-2)/2)
    else:
        tmp = int((C-1)*(C-2)/2)

    if (M <= tmp):
        clearrect(brd,R,C,R,C)
        n = 0
        x = R-1
        y = C-1
        z = 1
        while (n < M):
            brd[x][y]=1
            n += 1
            x -= 1
            y += 1
            if (y==C):
                z += 1
                x = R-1
                y = C-z
        return brd

    return []

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

fidi = open('C-large.in','r')
#fidi = open('test.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    
    R = tmp[0]
    C = tmp[1]
    M = tmp[2]
    
    # Find the solution

    brd = findsol(R,C,M)
    a = board2str(brd)
                
    # Show the output

    fido.write('Case #'+str(ii)+':\n'+a+'\n')
    print('Case #'+str(ii)+':\n'+a)

fidi.close()
fido.close()



