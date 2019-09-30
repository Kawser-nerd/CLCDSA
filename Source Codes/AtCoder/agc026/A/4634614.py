n=int(input())
slime=list(map(int,input().split()))
stack=0
count=0
ans=0
for i in slime:
  if i!=stack:
    stack=i
    ans+=((count+1)//2)
    count=0
    continue
  count+=1
  stack=i
ans+=((count+1)//2)
print(ans)