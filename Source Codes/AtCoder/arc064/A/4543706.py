n,x=map(int,input().split())
a=list(map(int,input().split()))
ret=0
if a[0]>x:
  ret+=a[0]-x
  a[0]-=a[0]-x
for i in range(n-1):
  if a[i+1]+a[i]>x:
    ret+=a[i+1]+a[i]-x
    a[i+1]-=a[i+1]+a[i]-x
print(ret)