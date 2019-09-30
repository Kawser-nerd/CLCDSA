n,m=map(int,input().split())
p=[1]*n
q=[0]*n
q[0]+=1
for i in range(m):
    x,y=map(int,input().split())
    p[y-1]+=1
    p[x-1]-=1
    if q[x-1]==1:
        q[y-1]=1
        if p[x-1]==0:
            q[x-1]=0
print(sum(q))