[a,b,c] = [int(i) for i in input().split()]
if a + b != c and a - b != c:
  print("!")
elif a + b != c:
  print("-")
elif a - b != c:
  print("+")
else:
  print("?")