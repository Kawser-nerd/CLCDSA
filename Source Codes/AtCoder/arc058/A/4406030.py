N,K=map(int,input().split())
D=[int(x) for x in input().split()]
kazu=[9,8,7,6,5,4,3,2,1,0]
for item in D:
  kazu.remove(item)
p=[]
m=len(str(N))
for i in range(m):
  p.append(kazu[0]*(10**i))
p.sort(reverse=True)
j=0
while j<m:
  for i in range(1,len(kazu)):
    if sum(p)-p[j]+kazu[i]*(10**(m-j-1))>=N:
      p[j]=kazu[i]*(10**(m-j-1))
    else:
      break
  j+=1
if sum(p)<N:
  if kazu[-1]!=0:
    ans=0
    for i in range(m+1):
      ans+=kazu[-1]*(10**i)
  else:
    ans=kazu[-2]*(10)**m
else:
  ans=sum(p)
print(ans)