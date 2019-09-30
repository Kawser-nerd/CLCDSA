n=int(input())
s = list(map(int,input().split()))
li=[0]*9
for i in range(n):
  if s[i]<3200:
    b=s[i]//400
    li[b]+=1
  else:
    li[8]+=1

ans=0
for j in range(8):
  if li[j]!=0:
    ans+=1

c=ans+li[8]

if ans==0:
  print(1,c)
else:
  print(ans,c)