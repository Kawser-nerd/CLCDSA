n,m=map(int,input().split())
count=[0]*m
ans=0
arr=[]
for i in range(n):
  arr.append(list(map(int,input().split())))
  for j in range(1,arr[i][0]+1):
    count[arr[i][j]-1]+=1
for i in range(m):
  if count[i]==n:
    ans+=1
print(ans)