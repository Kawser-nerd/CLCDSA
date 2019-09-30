a, b, c=map(int, input().split())
if a%2==1 and b%2==1 and c%2==1:
  print(min(a*b, b*c, c*a))
else:
  print(0)