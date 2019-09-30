import math
N,M=map(int,input().split(' '))
if abs(N-M) not in (0,1):
  print(0)
else:
  x = math.factorial(N) % (10**9+7)
  y = math.factorial(M) % (10**9+7)
  print(((2 - abs(N-M))*x*y)%(10**9+7))