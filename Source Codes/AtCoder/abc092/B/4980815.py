import math

n=int(input())
d,r=map(int,input().split())
ans=r
for i in range(n):
  m=int(input())
  ans+=math.ceil(d/m)
print(ans)