import sys

A, B, C, X, Y = map(int, input().split())

a = min(A, 2*C)
b = min(B, 2*C)
ab = min(A+B, 2*C)
cost = 0

if ab < (a + b):
  if X == Y:
    print(ab * X)
    sys.exit()
  elif X > Y:
    cost += ab * Y
    if ab <= a:
      cost += ab * (X - Y)
      print(cost)
      sys.exit()
    else:
      cost += a * (X - Y)
      print(cost)
      sys.exit()
  else:       # (X < Y)
    cost += ab * X
    if ab <= b:
      cost += ab * (Y - X)
      print(cost)
      sys.exit()
    else:
      cost += b * (Y - X)
      print(cost)
      sys.exit()
else:
  print(a*X + b*Y)
  sys.exit()