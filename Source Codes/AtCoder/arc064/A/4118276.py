N,x=map(int,input().split())
a=list(map(int,input().split()))

ans=0
for i in range(N-1):
    if(a[i]+a[i+1]>x):
        s=(a[i]+a[i+1]-x)
        a[i+1]=max(a[i+1]-s,0)
        ans+=s
print(ans)