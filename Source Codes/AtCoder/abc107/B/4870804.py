H,W=map(int,input().split())
A=[]
indh=[]
indw=[]
A=[list(input()) for _ in range(H)]   
for i in reversed(range(H)):
    if set(A[i])==set('.'):
        A.pop(i)
import numpy as np
AT=list(np.array(A).T)
ansT=[]
for i in range(W):
    if set(AT[i])!=set('.'):
        ansT.append(AT[i])
for a in list(np.array(ansT).T):
    print(''.join(a))