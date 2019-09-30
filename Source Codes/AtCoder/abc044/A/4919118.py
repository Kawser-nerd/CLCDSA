A, B, C, X = map(int, open(0).read().split())
if A-B <= 0:
  print(A*C)
else:
  print(B*C + (A-B)*X)