a,b = map(int,input().split())
x = (a+b)/2
if x-int(x)>=0.5:
  print(int(x)+1)
else:
  print(int(x))