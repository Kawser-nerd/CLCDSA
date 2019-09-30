a, b, c = map(int, input().split())

if max(a,b,c) == (a+b+c)-max(a,b,c):
  print("Yes")
else:
  print("No")