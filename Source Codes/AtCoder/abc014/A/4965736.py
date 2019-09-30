n=int(input())
m=int(input())
if int(n/m) == 0:
  print(m-n)
elif n%m == 0:
  print(0)
else:
  print(m-n%m)