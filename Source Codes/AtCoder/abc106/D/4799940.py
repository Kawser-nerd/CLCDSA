import numpy as np
N,M,Q = map(int,input().split())
c = [[0]*(N+1) for i in range(N+1)]
for i in range(M):
    l,r = map(int,input().split())
    c[l][r] += 1
c = np.cumsum(np.cumsum(c,axis=0),axis=1)
for i in range(Q):
    p,q = map(int,input().split())
    print(c[q][q]-c[q][p-1]-c[p-1][q]+c[p-1][p-1])