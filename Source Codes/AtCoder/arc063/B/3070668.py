from collections import defaultdict
N,T=map(int,input().split())
A=[int(i) for i in input().split()]
mi=A[0]
s=0
dd=defaultdict(int)
for i in range(1,N):
    mi=min(mi,A[i])
    s=max(A[i]-mi,s)
    dd[A[i]-mi]+=1
print(dd[s])