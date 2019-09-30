M_ab=400
M_n=40
inf=float('inf')
n,Ma,Mb=map(int,input().split())
A,B,C=[],[],[]
for _ in range(n):
    a,b,c=map(int,input().split())
    A.append(a)
    B.append(b)
    C.append(c)
DP=[[[inf]*(M_ab+1) for _ in range(M_ab+1)] for _ in range(M_n+1)]
DP[0][0][0]=0
for i in range(n):
    for ca in range(M_ab+1):
        for cb in range(M_ab+1):
            if DP[i][ca][cb]==inf:
                continue
            DP[i+1][ca][cb]=min(DP[i+1][ca][cb],DP[i][ca][cb])
            DP[i+1][ca+A[i]][cb+B[i]]=min(DP[i+1][ca+A[i]][cb+B[i]],DP[i][ca][cb]+C[i])
ans=inf
for ca in range(1,M_ab+1):
    for cb in range(1,M_ab+1):
        if ca*Mb==cb*Ma:
            ans=min(ans,DP[n][ca][cb])
if ans==inf:
    ans=-1
print(ans)