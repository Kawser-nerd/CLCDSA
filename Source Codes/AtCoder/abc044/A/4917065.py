from sys import stdin

a = int(input())
b = int(input())
c = int(input())
d = int(input())
if a < b:
  print(a*c)
else:
  print(b*c+d*(a-b))