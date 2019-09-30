from math import *

Q = int(input())
r = []
for x in range(Q):
  A = [int(i) for i in input().split(' ')]
  x = A[0] * A[1]
  s = floor(sqrt(x))
  if s*s == x:
    if (A[0] != s): r.append(2*s - 3)
    else: r.append(2*s-2)
  elif (s*(s+1) < x):
    r.append(2*s - 1)
  else: 
    r.append(2*s - 2)

for i in r:print(i)