import sys

N,M,Q=map(int,input().split())

a=[[0]*(N+1) for i in range(N+1)]

for i in range(M):
    L,R=map(int,input().split())
    a[L][R]+=1

b=[[0]*(N+1) for i in range(N+1)]

for i in range(1,N+1):
    for j in range(i,N+1):
        b[i][j]=a[i][j]+b[i][j-1]

ans=[[0]*(N+2) for i in range(N+2)]
for q in range(1,N+1):
    for p in range(q,0,-1):
        ans[p][q]=ans[p+1][q]+b[p][q]

for i in range(Q):
        p,q=map(int,input().split())
        print(ans[p][q])