import sys

n = int(input())
a, b = divmod(n, 100)

if (n % 111 == 0):
  print(n)
  sys.exit()

if (11*a > b):
  print(111 * a)
else :
  print(111 * (a+1))