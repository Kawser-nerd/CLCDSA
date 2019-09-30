n,m=map(int,input().split())

hoge=[]
huga=[]
for i in range(n):
  hoge.append(list(input()))
  
for i in range(m):
  huga.append(list(input()))
ans=0
for i in range(1+n-m):
  for j in range(1+n-m):
    flag=0
    for k in range(m):
      for l in range(m):
        if(hoge[i+k][j+l]!=huga[k][l]):
          flag+=1
    if(flag==0):
      ans+=1
if(ans==0):
  print("No")
else:
  print("Yes")