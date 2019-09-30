n,m=map(int,input().split());res=[0]*m
for _ in [0]*n:
  _,*o=map(int,input().split())
  for x in o:
    res[x-1]+=1
ans=res.count(n)
print(ans)