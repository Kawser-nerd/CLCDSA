import numpy as np
import random as rx
import math

f = open('test', 'r')
numcases = int(f.readline().rstrip('\n'))

for i in range(1,numcases+1):
    x = f.readline().rstrip('\n')
    count = 0

    #int(x.split()[0])
    #float(x.split()[0])


    ans = x[0]
    for j in range(1,len(x)):
        if ans[0] > x[j]:
            ans = ans+x[j]
        else:
            ans = x[j]+ans

    print "Case #" + str(i) +": " + ans

    #if x[len(x)-1] == '-':
        #count = count+1


