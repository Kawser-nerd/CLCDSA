mod=10**9+7
n,m=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
xl=0
xt=0
yl=0
yt=0
for i in range(n-1):
  if i==0:
    for j in range(1,n):
      xt+=x[j]-x[i]
    xl=xt
  else:
    xt-=(x[i]-x[i-1])*(n-i)
    xl=(xl+xt)%mod
for i in range(m-1):
  if i==0:
    for j in range(1,m):
      yt+=y[j]-y[i]
    yl=yt
  else:
    yt-=(y[i]-y[i-1])*(m-i)
    yl=(yl+yt)%mod
print(xl*yl%mod)