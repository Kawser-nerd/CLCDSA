import numpy as np
n=int(input())
a=[list(input()) for i in range(n)]
a=np.array(a)
c=0
for i in range(n):
    a=np.roll(a,1,axis=0)
    if len(a[a!=a.T])==0:c+=n
print(c)