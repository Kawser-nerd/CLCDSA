from sys import stdin
from numpy import *

def adj(N):
    X = identity(N)
    for i in range(N):
        Y = (outer(ones(N), X[i]) + (N-1)*X)/N
        Y[i] = X.sum(axis=1)/N
        X = Y
    return X

T = int(stdin.readline())
M = log(adj(1000))

for t in range(1,T+1):
    N = int(stdin.readline())
    assert N == 1000
    P = [int(word) for word in stdin.readline().strip().split()]

    l = 0.0
    for i in range(N):
        l += M[ i, P[i] ] + log(N)
    
    print "Case #"+str(t)+": "+("GOOD" if l<0.0 else "BAD")
