a,b,x=map(int,input().split())
if a==0:
  print(int(b//x)+1)
else:
  print(int(b//x)+1-int((a-1)//x)-1)