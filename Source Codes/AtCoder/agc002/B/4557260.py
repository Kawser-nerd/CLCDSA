n,m=map(int,input().split())
l=[[0]*2 for i in range(n)]
l[0][0]=1
for i in range(n-1):
    l[i+1][1]=1
for i in range(m):
    a,b=map(int,input().split())
    a=a-1
    b=b-1
    if l[a][0]>0:
        l[a][0]-=1
        l[b][0]+=1
    else:
        l[a][1]-=1
        l[b][1]+=1
    if l[b][0]>0:
        l[b][0]+=l[b][1]
        l[b][1]=0

ans=0
for i in range(n):
    if l[i][0]>0:
        ans+=1
print(ans)