n,a,b,k=map(int,input().split())
s=0
m=998244353
f=[1]
r=[1]
 
for i in range(1,n+1):
  f+=[i*f[i-1]%m]
  r+=[pow(f[i],m-2,m)]

cb=lambda x,y:f[x]*r[x-y]*r[y]

for i in range(n+1):
  c,d=divmod(k-a*i,b)
  if d==0 and 0<=c<=n:
    s=(s+cb(n,i)*cb(n,c))%m

print(s)