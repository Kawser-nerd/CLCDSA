a,b=input().split()

num=int(a+b)

if (num**0.5).is_integer():
  print("Yes")
else:
  print("No")