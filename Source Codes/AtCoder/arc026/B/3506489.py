from collections import defaultdict as dd
from functools import reduce

def calc(x):
  a,b=x
  v=0
  for i in range(b+1):
    v+=a**i
  return v

def factorization(n):
  d=dd(int)
  for i in range(2,1+int(n**0.5)):
    while n%i==0:
      d[i]+=1
      n//=i
  if n>1:d[n]+=1
  return d

n=int(input())
if n==1:
  print("Deficient")
else:
  d=factorization(n)
  result=reduce(lambda x,y:x*y,map(calc,d.items()))-n
  print("Perfect" if n==result else "Abundant" if result>n else "Deficient")