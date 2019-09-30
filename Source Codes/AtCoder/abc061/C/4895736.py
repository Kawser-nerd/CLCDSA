n,K=map(int,input().split());c={}
for i in range(n):
  a,b=map(int,input().split())
  if a in c:c[a]+=b
  else:c[a]=b
for k,v in sorted(c.items()):
  K-=v
  if K<=0:print(k);exit()