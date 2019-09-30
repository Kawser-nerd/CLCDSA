a, b = map(int, input().split())

if a > b:
  print(a * (b + 1))
else:
  print((a + 1) * b)