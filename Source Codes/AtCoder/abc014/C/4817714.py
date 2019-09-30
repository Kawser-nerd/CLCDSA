n=int(input())
m=[0 for i in range(1000001)]
for i in range(n):
  a,b=map(int,input().split())
  m[a]+=1
  if b<1000000:
    m[b+1]-=1
for i in range(1,1000001):
  m[i]+=m[i-1]
ans=0
for i in range(1000001):
  ans=max(ans,m[i])
print(ans)