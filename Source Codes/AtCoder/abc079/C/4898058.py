num = int(input())
a = num // 1000
b = num % 1000 // 100
c = num % 100 //10
d = num % 10

if a + b + c + d == 7:
  print(a, "+", b, "+", c, "+", d, "=", 7, sep='')
elif a + b + c - d == 7:
  print(a, "+", b, "+", c, "-", d, "=", 7, sep='')
elif a + b - c + d == 7:
  print(a, "+", b, "-", c, "+", d, "=", 7, sep='')
elif a + b - c - d == 7:
  print(a, "+", b, "-", c, "-", d, "=", 7, sep='')
elif a - b + c + d == 7:
  print(a, "-", b, "+", c, "+", d, "=", 7, sep='')
elif a - b + c - d == 7:
  print(a, "-", b, "+", c, "-", d, "=", 7, sep='')
elif a - b - c + d == 7:
  print(a, "-", b, "-", c, "+", d, "=", 7, sep='')
else:
  print(a, "-", b, "-", c, "-", d, "=", 7, sep='')