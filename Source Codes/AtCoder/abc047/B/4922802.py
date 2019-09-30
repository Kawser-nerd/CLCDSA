w,h,n=map(int,input().split())
xya=[list(map(int,input().split())) for i in range(n)]
m=[[0 for i in range(w)]for i in range(h)]
for x,y,a in xya:
    if a==1:
        for i in range(h):
            for j in range(x):
                m[i][j]=1
    elif a==2:
        for i in range(h):
            for j in range(x,w):
                m[i][j]=1
    elif a==3:
        for i in range(y):
            for j in range(w):
                m[i][j]=1
    else:
        for i in range(y,h):
            for j in range(w):
                m[i][j]=1
ans=0
for i in m:
    ans+=i.count(0)
print(ans)