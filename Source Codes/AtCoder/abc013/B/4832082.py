a = int(input())
b = int(input())

if a < b:
  print(min(b-a, a+10-b))
else:
  print(min(10-a+b, a-b))