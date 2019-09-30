N=int(input())
A=list(map(int,input().split()))
A=[0]+A
Aji=[0 for i in range(10**5+1)]
S=0
ans=0
F=0
E=0
for i in range(10**6):
    if F==N:
        break
    elif Aji[A[F+1]]==0:
        Aji[A[F+1]]=1
        F+=1
        S+=1
        if S>ans:
            ans=S
    elif Aji[A[F+1]]==1:
        Aji[A[E+1]]=0
        E+=1
        S-=1
    #print(Aji)
print(ans)