l,x,y,s,d = map(int, input().split())
m = (d-s)*(d>s) or l+d-s
if x>=y:
  print(m/(x+y))
else:
  print(min(m/(x+y),(l-m)/(y-x)))