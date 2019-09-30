n,m=map(int,input().split())
box=[1]*n
boxz=[1]+[0]*(n-1)
for i in range(m):
    x,y=map(int,input().split())
    box[y-1]+=1
    box[x-1]-=1
    if boxz[x-1]==1:
        boxz[y-1]=1
        if box[x-1]==0:
            boxz[x-1]=0
print(sum(boxz))