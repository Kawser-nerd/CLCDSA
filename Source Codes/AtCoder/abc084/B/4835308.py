a, b = map(int, input().split())
x = input().split("-")

if len(x) !=2:
  print("No")
  exit()

if len(x[0])==a and len(x[1])==b:
  print("Yes")
  exit()

print("No")