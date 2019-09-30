n,x=map(int, input().split())
a=list(map(int, input().split()))
b=a[:]
ans=float('inf')
for i in range(n):
    for j in range(n):
        b[j]=min(b[j],a[j-i])
    ans=min(ans,sum(b)+x*i)
print(ans)