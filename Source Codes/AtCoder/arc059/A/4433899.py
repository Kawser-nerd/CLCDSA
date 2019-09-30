N=int(input())
A=list(map(int,input().split()))

ans=float("inf")
for i in range(-100,101):
  tmp=0
  for  a in A:
    tmp+=(a-i)**2
  ans=min(ans, tmp)
print(ans)