import numpy as np
h,w=map(int, input().split())
s=np.array([list(input()) for i in range(h)])
def sh(p,p1,a):
    for i in range(h):
        for j in range(w):
            if p[i,j]==a:
                p1[max(0,i-1):i+2,max(0,j-1):j+2]=a
    return p1
ns=sh(s,np.copy(s),'.')
if (s==sh(ns,np.copy(ns),'#')).all():
    print('possible')
    for i in ns:print(*i,sep='')
else:print('impossible')