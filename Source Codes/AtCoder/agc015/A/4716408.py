n, a, b = map(int, input().split())
if n == 1 and a != b:
  print(0)
else:
  print(max(0,(n - 2) * (b - a) + 1))