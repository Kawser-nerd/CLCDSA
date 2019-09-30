
# coding: utf-8

# In[10]:

import sys
import numpy as np

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return np.array([int(i) for i in getWords()], dtype=np.int64)

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

#sys.stdin = open('A.in')

T = getInt()
for caseNo in xrange(1,T+1):
    S = getWords()[0]
    
    A = np.array([s=='C' for s in S])
    N = len(S)
    imbalance = abs( (A* (1-2*(np.arange(N)%2))).sum() )
    
    print "Case #%d: %d"%(caseNo, (N-imbalance)*5)


# In[ ]:



