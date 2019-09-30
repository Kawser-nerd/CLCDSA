n,m=map(int,input().split())

hoge=[]
hoge.append(["."]*(m+2))
for i in range(n):
  hoge.append(["."]+list(input())+["."])
hoge.append(["."]*(m+2))

for i in range(n):
  for j in range(m):
    a=i+1
    b=j+1
    if(hoge[a][b]=="#"):
      print("#",end="")
    else:
      ans=0
      if(hoge[a-1][b-1]=="#"):
        ans+=1
      if(hoge[a-1][b]=="#"):
        ans+=1
      if(hoge[a-1][b+1]=="#"):
        ans+=1
      if(hoge[a][b-1]=="#"):
        ans+=1
      if(hoge[a][b+1]=="#"):
        ans+=1
      if(hoge[a+1][b-1]=="#"):
        ans+=1
      if(hoge[a+1][b]=="#"):
        ans+=1
      if(hoge[a+1][b+1]=="#"):
        ans+=1
      print(ans,end="")
  print("")