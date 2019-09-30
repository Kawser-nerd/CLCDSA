n=int(input())
hoge=list(map(int,input().split()))
kei=sum(hoge)
hei=kei/n
nokori=0
ans=0
if(kei%n>0):
  print(-1)
else:
  for i in range(n-1):
    nokori+=hoge[i]
    if(nokori != hei*(i+1)):
      ans+=1
  print(ans)