n = int(input())
s = 0
x = 1
while x*x <n:
  if n%x == 0:
    s += x + n//x
  x += 1
if x*x ==n:
  s += x
if s < 2*n:
  print("Deficient")
elif s == 2*n:
  print("Perfect")
else:
  print("Abundant")