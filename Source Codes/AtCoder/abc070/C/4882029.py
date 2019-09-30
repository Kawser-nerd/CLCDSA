from fractions import gcd
from functools import reduce
n=int(input())
l=[int(input()) for i in range(n)]
def lcm(x,y):
  return x*y//gcd(x,y)
def lcm_list(numbers):
  return reduce(lcm,numbers,1)
ans=lcm_list(l)
print(ans)