n,t=map(int,input().split())
a=list(map(int,input().split()))
s=0
for i in range(n-1):
  s+=min(t,a[i+1]-a[i])
print(s+t)