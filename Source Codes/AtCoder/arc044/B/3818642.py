def rui(a,m,w):
  r=1
  while m>0:
    if m & 1:
      r=r*a%w
    a=a*a%w
    m>>=1
  return r
n=int(input())
a=list(map(int,input().split()))
ans=0
w=10**9+7
if a[0]==0 and a.count(0)==1:
  a.sort()
  ans=now=old=1
  b=0
  for i in range(1,n):
    if b!=a[i]:
      if a[i]-b==1:
        ans*=rui(2,now*(now-1)//2,w)
        ans%=w
        old=now
        now=0
        b=a[i]
      else:
        ans=0
        break
    ans*=rui(2,old,w)-1
    ans%=w
    now+=1
    if i==n-1:
      ans*=rui(2,now*(now-1)//2,w)
      ans%=w
print(ans)