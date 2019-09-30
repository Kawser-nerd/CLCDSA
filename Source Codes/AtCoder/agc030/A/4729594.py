A, B, C = map(int, input().split())

if A + B >= C:
  print(B + C)
else:
  print(A + B + B + 1)