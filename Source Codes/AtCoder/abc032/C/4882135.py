import sys
n,k=map(int,input().split())
line=[int(i) for i in sys.stdin]
flag=False
stack=1
start=0
ans=0
answer=0
for i in range(n):
  if line[i]==0:
    print(n)
    exit()
  if stack*line[i]<=k:
    stack*=line[i]
    ans+=1
  else:
    answer=max(answer,ans)
    stack*=line[i]
    ans+=1
    while stack>k and start<=i:
      stack//=line[start]
      start+=1
      ans-=1
answer=max(ans,answer)
print(answer)