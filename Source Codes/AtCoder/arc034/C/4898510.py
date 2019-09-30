from collections import defaultdict as dd

A,B=map(int,input().split())

D=dd(int)

for i in range(B+1,A+1):
    N=i
    for j in range(2,10**5+1):
        while N%j==0:
            D[j]+=1
            N//=j
    if N>10**5:
        D[N]+=1
        
ans=1
for i in D:
    ans*=(D[i]+1)
    #print(D)
    ans%=(10**9+7)
print(ans)