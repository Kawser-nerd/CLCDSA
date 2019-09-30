n,m=map(int,input().split())
a=[list(map(int,input().split()))for i in range(m)]
s=[[float("inf")]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
    s[i][i]=0
for i in range(m):
    s[a[i][0]][a[i][1]]=a[i][2]
    s[a[i][1]][a[i][0]]=a[i][2]
for h in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if s[i][j]>s[i][h]+s[h][j]:
                s[i][j]=s[i][h]+s[h][j]
c=0
for i in range(m):
    for j in range(1,n+1):
        if s[j][a[i][0]]!=float("inf"):
            if s[j][a[i][0]]+a[i][2]==s[j][a[i][1]]:
                break
    else:
        c+=1
print(c)