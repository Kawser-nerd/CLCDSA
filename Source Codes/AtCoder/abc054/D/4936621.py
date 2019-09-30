#D??
NM=40
ABM=10
MM=400

N,M1,M2=map(int,input().split())
A=[]
B=[]
C=[]
for i in range(N):
    a,b,c=map(int,input().split())
    A.append(a)
    B.append(b)
    C.append(c)
cmax=max(C)
CM=N*cmax+10
dp=[[[CM for broop in range(401)] for aroop in range(401)] for nroop in range(N+1)]
dp[0][0][0]=0
for i in range(N):
    for cb in range(401):
        for ca in range(401):
            if dp[i][ca][cb]==CM:
                continue
            dp[i+1][ca][cb]=min(dp[i+1][ca][cb],dp[i][ca][cb])
            if ca+A[i]<401 and cb+B[i]<401:
                dp[i+1][ca+A[i]][cb+B[i]]=min(dp[i+1][ca+A[i]][cb+B[i]],dp[i][ca][cb]+C[i])

ans=CM
for cb in range(400):
    for ca in range(400):
        CB=cb+1
        CA=ca+1
        if CA*M2 == CB*M1:
            ans=min(ans,dp[N][CA][CB])

if ans == CM:
    print(-1)
else:
    print(ans)