a, b, c = map(int,open(0).read().split())
if a + b == c or a + c == b or b + c == a:
  print("Yes")
else:
  print("No")