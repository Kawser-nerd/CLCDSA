n=int(input())
l=input()
d=dict()
for a in l:
  if not a in d:
    d[a]=1
  else:
    d[a]+=1
ans=1
for a in d.values():
  ans*=a+1
print((ans-1)%(10**9+7))