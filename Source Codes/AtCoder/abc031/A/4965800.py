a,b=map(int,input().split())
if (a+1)*b >= a*(b+1):
  print((a+1)*b)
else:
  print(a*(b+1))