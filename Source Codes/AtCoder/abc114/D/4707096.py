import math
from collections import Counter
import itertools

def prime_factors(n):
  i = 2
  factors = []
  while i * i <= n:
    if n % i==0:
      n //= i
      factors.append(i)
    else:
      i += 1
  if n > 1:
    factors.append(n)
  return factors

n=int(input())
num=math.factorial(n)
factors=prime_factors(num)
es=list(Counter(factors).values())
m=len(es)
ans=0

for i in range(m):
  if es[i]>=74:
    ans+=1

for i in range(m):
  for j in range(m):
    if i!=j and es[i]>=24 and es[j]>=2:
      ans+=1

for i in range(m):
  for j in range(m):
    if i!=j and es[i]>=14 and es[j]>=4:
      ans+=1

for i in range(m):
  for j in range(i+1,m):
    for k in range(m):
      if i!=k and j!=k and es[i]>=4 and es[j]>=4 and es[k]>=2:
        ans+=1
print(ans)