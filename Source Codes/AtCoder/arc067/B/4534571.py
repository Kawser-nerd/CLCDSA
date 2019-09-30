n,a,b=map(int,input().split())
x=list(map(int,input().split()))
ans=0
for i in range(n-1):
    ans+=min(a*(x[i+1]-x[i]),b)
print(ans)