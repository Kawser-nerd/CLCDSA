a,b,c=map(int,input().split())
if a + b >= c :
  print(b+c)
elif a==b==c==0:
  print(0)
else:
  print(a+2*b+1)