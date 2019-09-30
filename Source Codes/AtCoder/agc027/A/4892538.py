n,x=map(int,input().split())
l=list(map(int,input().split()))
l.sort()
if x==sum(l):
  print(n)
elif x>sum(l):
  print(n-1)
else:
  ans=0
  k=0
  for a in l:
    k+=a
    if k>x:
      break
    ans+=1
  print(ans)