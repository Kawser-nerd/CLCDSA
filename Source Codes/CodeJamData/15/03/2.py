# Written in Python 3.3

import math
import sys
import random

def qneg(a):
    qmap = {}
    qmap['1']='-'
    qmap['-']='1'
    qmap['i']='I'
    qmap['I']='i'
    qmap['j']='J'
    qmap['J']='j'
    qmap['k']='K'
    qmap['K']='k'
    return qmap[a]

# Multiply quaternions

def qmult(a,b):

    nn = 0
    if (a in ['-','I','J','K']):
        nn += 1
        a = qneg(a)
    if (b in ['-','I','J','K']):
        nn += 1
        b = qneg(b)

    qmap = {}
    if (a=='1'):
        qmap['1']='1'
        qmap['i']='i'
        qmap['j']='j'
        qmap['k']='k'
    if (a=='i'):
        qmap['1']='i'
        qmap['i']='-'
        qmap['j']='k'
        qmap['k']='J'
    if (a=='j'):
        qmap['1']='j'
        qmap['i']='K'
        qmap['j']='-'
        qmap['k']='i'
    if (a=='k'):
        qmap['1']='k'
        qmap['i']='j'
        qmap['j']='I'
        qmap['k']='-'

    c = qmap[b]

    if nn == 1:
        c = qneg(c)

    return c

def checkforq(S1,S2):
    #print(len(S1),S2)
    v = '1'
    for ii in range(len(S1)):
        v = qmult(v,S1[ii])
        if (v==S2[0]):
            if len(S2)==1:
                if (ii==len(S1)-1):
                    return 'YES'
            else:
                return checkforq(S1[ii+1:],S2[1:])
    return 'NO'

def findsol(S,L,X2):

    # Any split containing 4 repetitions is equivalent to 1

    X = X2 % 12
    if (X2 > 12):
        X += 12

    # Quick check that it is even possible

    a = '1'
    for ii in S:
        a = qmult(a,ii)
    b = a
    for ii in range(X-1):
        b = qmult(b,a)
        
    if not(b=='-'):
        return 'NO'

    # Check the full repeated string

    S2 = ''
    for ii in range(X):
        S2 += S
    return checkforq(S2,'ijk')


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
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

#T = 1
#random.seed(4)
for ii in range(1,T+1):
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    
    L = tmp[0]  # Length of sequence
    X = tmp[1]  # Number of repeats

    S = fidi.readline()
    S = S[0:L]

    #L = 10000
    #X = 23

    #a='ijk'
    #S = ''
    #for jj in range(L):
    #    S += a[random.randint(0,2)]
    
    # Find the solution

    a = findsol(S,L,X)
     
    # Show the output

    fido.write('Case #'+str(ii)+': '+a+'\n')
    print('Case #'+str(ii)+': '+a)

fidi.close()
fido.close()

