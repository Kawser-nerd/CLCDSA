n, a, b = map(int, input().split())
m = n % (a+b)
if 0 < m <= a:
  print("Ant")
else:
  print("Bug")