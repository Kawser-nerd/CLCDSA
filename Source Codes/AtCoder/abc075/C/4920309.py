n,m=map(int,input().split());a,ans=[[],[]],0
for i in range(m):aa,bb=map(int,input().split());a[0].append(aa);a[1].append(bb)
flag=True
while flag:
  flag=False
  for i in range(1,n+1):
    c=0
    p=[]
    for j in range(len(a[0])):
      if a[0][j]==i:c+=1;p.append(j)
      if a[1][j]==i:c+=1;p.append(j)
      if c>1:break
    if c==1:
      ans+=1
      del a[0][p[0]],a[1][p[0]]
      flag=True
      break
print(ans)