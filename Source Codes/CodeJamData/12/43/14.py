from __future__ import division
import sys, string
import itertools
from math import *

def readlist():
	return [int(x) for x in sys.stdin.readline().strip().split(" ")]

T = int(sys.stdin.readline())

def try_increment(N,H,L):
    #~ print N,H
    for i in range(N-1): # L[i] e varful cel mai de sus, vazut din i
        #~ print i, L[i]
        lhs = (H[L[i]-1] - H[i]) / (L[i]-1 - i)
        for j in range(i+1, N):  # adica, (H[L[i]] - H[i]) / (L[i]-i) > (H[j] - H[i]) / (j-i) oricare ar fi j != L[i]
            if j != L[i]-1:
                rhs = (H[j] - H[i]) / (j-i)
                if lhs <= rhs:
                    H[L[i]-1] += 1
                    return 1
    return 0

for k in range(T):
    
    N = int(sys.stdin.readline());
    L = readlist()
    
    
    H = [0] * N
    
    found=0
    for a in range(100000):
        if not try_increment(N,H,L):
            found=1
            break

    if not found:
        ans = "Impossible"
    else:
        ans = string.join(["%s"%h for h in H])
    
    print "Case #%d: %s" % ((k+1), ans)
    
    
