import math
n = int(input())
a = 1
b = 1
for i in range(1, math.floor(math.sqrt(n))+1):
  if n % i == 0:
    a = n / i
    
b = n / a
print(max([len(list(str(int(a)))), len(list(str(int(b))))]))