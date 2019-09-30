n,m=map(int,input().split())
d=[[10**18]*n for i in range(n)]
e=[]
for _ in range(m):
    a,b,c=map(int,input().split())
    d[a-1][b-1]=c
    d[b-1][a-1]=c
    e.append([a-1,b-1,c])
for i in range(n):
    d[i][i]=0
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j]=min(d[i][j],d[i][k]+d[k][j])
print(sum(c>d[a][b]for a,b,c in e))