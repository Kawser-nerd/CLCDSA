A, B = map(int, input().rstrip().split())

if B % A == 0:
  print(A+B)
else:
  print(B-A)