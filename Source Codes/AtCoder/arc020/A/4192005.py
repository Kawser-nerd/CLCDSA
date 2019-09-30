A, B = map(int, input().split())

if abs(A) < abs(B):
  print("Ant")
elif abs(A) > abs(B):
  print("Bug")
else:
  print("Draw")