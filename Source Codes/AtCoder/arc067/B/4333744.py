n,a,b=map(int,input().split())
x=list(map(int,input().split()))
ans=0
for i in range(n-1):
    ans+=min((x[i+1]-x[i])*a,b)
print(ans)