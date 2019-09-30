n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=sum(a)*k
for i in range(k-1):
    ans-=a[i]*(k-1-i)
for j in range(k-1):
    ans-=a[-1-j]*(k-1-j)
print(ans)