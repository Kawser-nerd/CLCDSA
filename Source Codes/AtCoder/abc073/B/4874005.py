n=int(input())
ans=0
for i in range(n):
  r,l=(int(i) for i in input().split())
  ans+=l-r+1
print(ans)