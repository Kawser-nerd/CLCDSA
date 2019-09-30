n,a,b=map(int,input().split())
if a>b:
  print(0)
elif n==1 and a<b:
  print(0)
else:
  print((b-a)*(n-2)+1)