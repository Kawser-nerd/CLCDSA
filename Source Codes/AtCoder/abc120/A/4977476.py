a,b,c=map(int,input().split())
res=0
if a>b:
  res=0
else:
  res=b//a
if res<=c:
  print(res)
else:
  print(c)