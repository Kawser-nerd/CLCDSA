n=int(input())
l=[0]+list(map(int,input().split()))
for i in range(1,n+1):
  l[i]+=l[i-1]
d={}
for i in l:
  if i not in d:
    d[i]=1
  else:
    d[i]+=1
ans=0
for a in d.values():
  ans+=a*(a-1)//2
print(ans)