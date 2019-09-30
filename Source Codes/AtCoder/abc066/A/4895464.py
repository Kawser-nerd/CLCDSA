a, b, c=map(int, input().split())
if a+b<=b+c and a+b<=a+c:
  print(a+b)
elif b+c<=a+b and b+c<=a+c:
  print(b+c)
else:
  print(a+c)