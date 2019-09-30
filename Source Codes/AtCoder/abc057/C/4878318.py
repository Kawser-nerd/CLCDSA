import math
N = int(input())
n = int(math.sqrt(N))
p = 1
while True:
  p = N//n
  if n*p == N:
    break
  else:
    n -= 1
print(max(len(str(n)),len(str(p))))