A, B, C, X, Y = map(int,input().split())
if(A + B >= 2 * C):
  if(X >= Y):
    print(C * 2 * Y + (X - Y) * min(A, 2 * C))
  else :
    print(C * 2 * X + (Y - X) * min(B, 2 * C))
else:
  print(A * X + B * Y)