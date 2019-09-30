a,b = map(int,input().split(" "))
if a == 1 and b == 1:
  print(1)
elif a == 1 or b == 1:
  print(a * b - 2)
else:
  print((a-2) * (b-2))