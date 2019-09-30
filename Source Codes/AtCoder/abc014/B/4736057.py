n,m=map(int,input().split())
l=list(map(int,input().split()))
sum=0
for i in range(1,n+1):
  if 2**(n-i)<=m:
    m-=2**(n-i)
    sum+=l[-i]
print(sum)