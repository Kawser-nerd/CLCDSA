a,b,ab,x,y=map(int,input().split())
m=min(x,y)
if a+b >= 2*ab:
  if x <= y:
    if ab*2 > b:
      print(ab*2*m + (y-x)*b)
    else:
      print(y*ab*2)
  else:
    if ab*2 > a:
      print(ab*2*m + (x-y)*a)
    else:
      print(ab*2*x)
else:
  print(a*x + b*y)