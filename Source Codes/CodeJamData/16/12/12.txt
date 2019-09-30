import numpy as np
import random as rx
import math

f = open('test', 'r')
numcases = int(f.readline().rstrip('\n'))

for i in range(1,numcases+1):
    x = int(f.readline().rstrip('\n'))

    q = np.zeros(2501)
    for j in range(0,x*2-1):
        y = f.readline().rstrip('\n')
        y = y.split()
        for l in range(0,x):
            k = int(y[l])
            q[k] = (q[k]+1) % 2

    ans = ""
    for j in range(0,2501):
        if q[j] == 1:
            ans = ans + " " + str(j)



    print "Case #" + str(i) +":" + ans

    #if x[len(x)-1] == '-':
        #count = count+1


