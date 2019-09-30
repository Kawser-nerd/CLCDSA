n=int(input())
t,a=map(int,input().split())
h=list(map(int,input().split()))
nr=10**10
ans=0
for i in range(n):
  tmp=t-h[i]*0.006
  tmp=abs(a-tmp)
  if tmp<nr:
    nr=tmp
    ans=i
print(ans+1)