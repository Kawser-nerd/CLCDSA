n,k=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a)[::-1]
ans=0
for i in range(k):
  ans+=a[i]
print(ans)