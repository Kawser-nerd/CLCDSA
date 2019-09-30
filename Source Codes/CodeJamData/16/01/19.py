# Written in Python 3.3

import math
import sys

def base10(N):
    t=[]
    while (N>0):
        t.append(N%10)
        N=int((N-t[-1])/10)
    return t

def findsol(N):
    if (N==0):
        return 'INSOMNIA'

    z = [0,0,0,0,0,0,0,0,0,0]
    f = 0
    b = 1

    while 1:
        a = base10(N*b)
        for jj in a:
            if (z[jj]==0):
                f += 1
            z[jj] = 1      
        if (f==10):
            return N*b

        b += 1
        
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
    N = int(fidi.readline())
      
    # Find the solution

    a = findsol(N)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #'+str(ii),': ',str(a))

fidi.close()
fido.close()



