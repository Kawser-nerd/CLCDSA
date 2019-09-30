import numpy as np
import random as rx
import math

f = open('test', 'r')
numcases = int(f.readline().rstrip('\n'))

for i in range(1,numcases+1):
    x = int(f.readline().rstrip('\n'))
    y = f.readline().rstrip('\n')
    y = y.split()
    yy = np.ones(x)
    need = -1*np.ones(x)

    for j in range(0,x):
        yy[j] = int(y[j])-1

    type = np.zeros(x)
    for j in range(0,x):
        seen = np.zeros(x)
        if yy[yy[j]] == j:
            type[j] = 1

    for j in range(0,x):
        seen = np.zeros(x)
        if yy[yy[j]] == j:
            type[j] = 1
        else:
            temp = j

            type[j] = 1
            seen = np.zeros(x)
            while(1):
                temp = yy[temp]
                type[j]=type[j]+1
                if type[temp]==1:
                    type[j] = -1*type[j]+1
                    need[j] = temp
                    break
                if seen[temp] == 1:
                    type[j] = -1*type[j]+1
                    need[j] = -5
                    break
                if temp == j:
                    type[j]=type[j]-1
                    break
                seen[temp] =1

    singleloop = max(type)

    duos = 0
    for j in range(0,x):
        if type[j] == 1:
            duos = duos+1

            possiblemax = 0
            for k in range(0,x):
                if need[k] == j and possiblemax < -1*type[k]:
                    possiblemax = -1*type[k]
            duos = possiblemax + duos

    ans = ""
    duos = max(duos,singleloop)
    duos = int(duos)
#179,4,(3T)


    print "Case #" + str(i) +": " + str(duos)

    #if x[len(x)-1] == '-':
        #count = count+1


