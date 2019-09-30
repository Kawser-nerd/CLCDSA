n,m=map(int,input().split())
brighes=[list(map(lambda x:int(x)-1,input().split()))for i in range(m)]
neighbor=[set()for i in range(n)]
for brighe in brighes:
  v1,v2=brighe
  neighbor[v1].add(v2)
  neighbor[v2].add(v1)
  
ans=0
for brighe in brighes:
  v=[0 for i in range(n)]
  v[brighe[0]]=1
  stack=[]
  for a in neighbor[brighe[0]]:
    if a!=brighe[1]:
      stack.append(a)
  while stack!=[]:
    a=stack.pop()
    v[a]=1
    for b in neighbor[a]:
      if v[b]!=1:
        stack.append(b)
  if v[brighe[1]]==0:
    ans+=1
print(ans)