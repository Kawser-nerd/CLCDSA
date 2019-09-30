import numpy as np
n,m,q=map(int,input().split())
s=np.zeros((n,n))
for i in range(m):
    l,r=map(int,input().split())
    s[n-l][r-1]+=1
s=np.cumsum(np.cumsum(s,axis=0),axis=1)
for i in range(q):
    d,t=map(int,input().split())
    print(int(s[n-d][t-1]))