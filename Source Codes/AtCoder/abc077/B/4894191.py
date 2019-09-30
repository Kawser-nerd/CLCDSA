import math
n=int(input())
for i in range(n,-1,-1):
  num=math.floor(math.sqrt(i))
  if num**2==i:
    break
print(i)