A,B,C,X,Y = map(int,input().split())
a,b,c = 0,0,0
if (A+B)/2 > C:
  c = min(X,Y)*2
  a = X-min(X,Y)
  b = Y-min(X,Y)
  if a*A > a*2*C:
    c += a*2
    a = 0
  if b*B > b*2*C:
    c += b*2
    b = 0
else:
  a = X
  b = Y
print(a*A+b*B+c*C)