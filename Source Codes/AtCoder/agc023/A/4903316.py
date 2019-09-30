from collections import defaultdict as dd

N=int(input())

A=list(map(int,input().split()))
B=[A[0]]
for i in range(1,N):
    B.append(B[i-1]+A[i])
    
D=dd(int)
Z=0
for i in range(N):
    if B[i]==0:
        Z+=1
    
    D[B[i]]+=1
    
ans=0
for i in D:
    
    ans+=((D[i]-1)*D[i]//2)
if Z>0:
    ans+=Z
    
print(ans)
#print(D)