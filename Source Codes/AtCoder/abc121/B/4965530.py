n,m,c=map(int,input().split())
b=list(map(int,input().split()))
a=[list(map(int,input().split())) for i in range(n)]
ans=0
for i in range(n):
  code=0
  for j in range(m):
    code+=a[i][j]*b[j]
  if code+c>0:
    ans+=1
print(ans)