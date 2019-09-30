A, B, _, K = map(int, input().split())
if K % 2 == 0:
  print(A - B)
else:
  print(B - A)