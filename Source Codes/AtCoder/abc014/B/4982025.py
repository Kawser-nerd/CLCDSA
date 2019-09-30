n,x=map(int,input().split())
l=list(map(int,input().split()))
ans=0
i=0
while x>0:
  if x%2==1:
    ans+=l[i]
  x//=2
  i+=1
print(ans)