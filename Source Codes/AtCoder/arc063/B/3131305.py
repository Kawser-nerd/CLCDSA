N,T=map(int,input().split())
A=[int(i) for i in input().split()]
B=[0 for i in range(N)]
B[0]=A[0]
for i in range(1,N):
    B[i]=min([B[i-1],A[i]])
C=[A[i]-B[i] for i in range(N)]
M=max(C)
ans=0
for i in range(N):
    if C[i]==M:
        ans+=1
print(ans)