n,c=map(int,input().split())
l=[list(map(int,input().split())) for i in range(n)]

rev=[None]*(n+1)
norm=[None]*(n+1)
revmax=[None]*(n+1)

rev[0]=(0,0)
revmax[0]=(0,0)
norm[0]=(0,0)
ans=0

# normal rotation
for i in range(1,n+1):
    x,v=l[i-1]
    norm[i]=(x,v+norm[i-1][1])

# reverse rotation
for i in range(1,n+1)[::-1]:
    x,v=l[i-1]
    if i==n:
        rev[i]=(c-x,v)
    else:
        rev[i]=(c-x,v+rev[i+1][1])

for i in range(1,n+1):
    revmax[-i]=(max(revmax[-i+1][0],rev[-i][1]-2*rev[-i][0]),max(revmax[-i+1][1],rev[-i][1]-rev[-i][0]))

for i in range(n+1):
    v1=norm[i][1]-norm[i][0]+revmax[i-n][0]
    v2=norm[i][1]-2*norm[i][0]+revmax[i-n][1]
    ans=max(ans,v1,v2)

print(ans)