A, D = map(int, input().split())
x = (A + 1) * D
y = A * (D + 1)
if x >= y:
  print(x)
else:
  print(y)