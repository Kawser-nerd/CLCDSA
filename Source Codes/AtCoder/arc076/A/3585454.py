import math
N,M = map(int,input().split())
if abs(N - M) > 1:
  print(0)
elif N == M:
  print((2*(math.factorial(N) * math.factorial(M))) % 1000000007)
else:
  print(((math.factorial(N) * math.factorial(M))) % 1000000007)