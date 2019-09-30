import math
n=int(input())
a=math.floor(math.sqrt(n))

for i in range(1,a+1):
  if n%i==0:
    b=i

c=str(n/b)
print(len(c)-2)