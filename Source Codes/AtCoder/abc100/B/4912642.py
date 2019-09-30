d,n = [int(x) for x in input().split()]

if n == 100:
  print(pow(100,d)*101)
else:
  print(pow(100,d)*n)