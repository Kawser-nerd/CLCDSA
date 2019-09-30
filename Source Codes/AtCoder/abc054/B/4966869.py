n,m=map(int,input().split())
arr1=[[i for i in input()] for _ in range(n)]
arr2=[[i for i in input()] for _ in range(m)]
count=0
for i in range(n-m+1):
  for j in range(n-m+1):
    flag=True
    for k in range(m):
      for l in range(m):
        if arr1[i+k][j+l]!=arr2[k][l]:
          flag=False
    if flag:
      count+=1
if count>=1:
  print('Yes')
else:
  print('No')