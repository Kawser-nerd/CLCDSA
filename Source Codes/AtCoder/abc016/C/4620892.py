N,M=map(int,input().split())
data=[[3]*N for i in range(N)]
for i in range(N):
    data[i][i]=0
for m in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    data[a][b]=1
    data[b][a]=1
for i in range(N):
    for j in range(N):
        for k in range(N):
            data[i][j]=min(data[i][j],data[i][k]+data[k][j])
for i in range(N):
    print(data[i].count(2))