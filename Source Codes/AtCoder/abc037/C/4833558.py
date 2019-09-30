n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0
if n+1>=2*k:
  for i in range(k-1):
    ans+=a[i]*(i+1)
  for i in range(k-1,n-k+1):
    ans+=a[i]*k
  for i in range(n-k+1,n):
    ans+=a[i]*(n-i)
else:
  for i in range(n-k):
    ans+=a[i]*(i+1)
  for i in range(n-k,k):
    ans+=a[i]*(n-k+1)
  for i in range(k,n):
    ans+=a[i]*(n-i)
print(ans)