n=int(input())
ans=0
a=0
for i in map(int,input().split()):
  if not a==i:
    a=i
    continue
  ans+=1
  a=0
print(ans)