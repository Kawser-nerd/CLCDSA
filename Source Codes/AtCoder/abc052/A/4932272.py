from sys import stdin

a, b, c, d = [int(x) for x in stdin.readline().rstrip().split()]
if a*b >= c*d:
  print(a*b)
else:
  print(c*d)