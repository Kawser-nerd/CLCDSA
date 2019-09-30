n=int(input())
l=[list(map(int,input().split())) for i in range(n)]
ans=0
for i in range(n):
  ans=ans-l[i][0]+l[i][1]+1
print(ans)