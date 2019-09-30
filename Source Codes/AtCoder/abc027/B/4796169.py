n=int(input())

a=list(map(int,input().split()))

if not sum(a)%n==0:
  print(-1)
else:
  lastnum=sum(a)//n
  ans=0
  for i in range(1,n):
    if not (sum(a[:i])==lastnum*i and sum(a[i:])==lastnum*(n-i)):
      ans+=1
  print(ans)