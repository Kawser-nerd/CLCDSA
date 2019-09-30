# Written in Python 3.3

import math
import sys

def findsol(C1,C2):
    a = set(C1).intersection(set(C2))

    if len(a)==0:
        b = 'Volunteer cheated!'

    if len(a)==1:
        b = str(a.pop())

    if len(a)>1:
        b = 'Bad magician!'

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

fidi = open('A-small-attempt0.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    R1 = fidi.readline()
    R1 = int(R1)

    for jj in range(4):
        C = fidi.readline()
        if (jj == R1-1):
            C1 = convertnums(C)

    R2 = fidi.readline()
    R2 = int(R2)

    for jj in range(4):
        C = fidi.readline()
        if (jj == R2-1):
            C2 = convertnums(C)
    
    # Find the solution

    a = findsol(C1,C2)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



