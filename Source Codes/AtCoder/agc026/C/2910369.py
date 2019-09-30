import itertools
import bisect
N=int(input())
S=input()
ans=0
L=dict()
R=dict()
for seq in itertools.product([0,1],repeat=N):
    T0=""
    T1=""
    T2=""
    T3=""
    for i in range(N):
        if seq[i]==0:
            T0+=S[i]
            T2+=S[-i-1]
        else:
            T1+=S[i]
            T3+=S[-i-1]
    a0=len(T0)
    a1=len(T1)
    a2=len(T2)
    a3=len(T3)
    if (T0,T1) in L:
        L[(T0,T1)]+=1
    else:
        L[(T0,T1)]=1
    if (T2,T3) in R:
        R[(T2,T3)]+=1
    else:
        R[(T2,T3)]=1
for tup in L:
    if tup in R:
        ans+=L[tup]*R[tup]
print(ans)