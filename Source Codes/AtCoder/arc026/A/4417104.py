n, a, b = map(int, input().split())
if n <= 5:
  print(b*n)
else:
  print(b*5 + a*(n-5))