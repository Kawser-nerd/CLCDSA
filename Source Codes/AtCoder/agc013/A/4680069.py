n,*a=map(int,open(0).read().split())
tmp=0
ans=1
for i in range(len(a)-1):
    dif=a[i+1]-a[i]
    if tmp==0:
        tmp=dif
    elif dif*tmp<0:
        ans+=1
        tmp=0

print(ans)