n,m=map(int,input().split())
num=[1]*n
red=[True]+[False]*(n-1)
for _ in range(m):
    x,y=map(int,input().split())
    x-=1
    y-=1
    if red[x]:
        red[y]=True
    num[x]-=1
    num[y]+=1
    if not num[x]:
        red[x]=False
print(sum(red))