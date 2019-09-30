n,m=map(int,input().split())
name,kit=input(),input()
a,b=[i for i in name],[i for i in kit]
ans=0
while a.count(0)!=n:
  ans+=1
  c=a[:]
  for i in b:
    if i in a:a[a.index(i)]=0
  if a==c:
    ans=-1
    break
print(ans)