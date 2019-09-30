x, a, b = map(int, input().split())

if abs(a-x) < abs(b-x):
  print("A")
else:
  print("B")