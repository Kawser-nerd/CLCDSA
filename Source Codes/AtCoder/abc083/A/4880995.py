A,B,C,D = map(int, input().split())
left = A+B
right = C+D
if left > right:
  print("Left")
elif left < right:
  print("Right")
else:
  print("Balanced")