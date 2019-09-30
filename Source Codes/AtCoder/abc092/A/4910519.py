a=int(input())
b=int(input())
c=int(input())
d=int(input())
if a<=b and c<=d:
  print(a+c)
elif a<=b and c>=d:
  print(a+d)
elif a>=b and c<=d:
  print(b+c)
else:
  print(b+d)