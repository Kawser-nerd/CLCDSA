[x,a,b] = list(map(int, input().split()))
if abs(a-x) < abs(b-x):
  print("A")
else:
  print("B")