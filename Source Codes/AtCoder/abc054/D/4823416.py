mod=1777777777
n,ma,mb=map(int,input().split())
d=[[mod for j in range(100)] for i in range(100)]
for i in range(n):
    a,b,c=map(int,input().split())
    for j in range(100-a-1,-1,-1):
        for k in range(100-b-1,-1,-1):
            d[j+a][k+b]=min(d[j+a][k+b],d[j][k]+c)
    d[a][b]=min(d[a][b],c)
ans=mod
for i in range(100):
    if i%ma==0 and mb*i//ma<100:
        ans=min(ans,d[i][mb*i//ma])

print([ans,-1][ans==mod])