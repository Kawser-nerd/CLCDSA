import fractions
from functools import reduce
 
def lcm_base(x, y):
  return (x*y)//fractions.gcd(x, y)
 
def lcm_list(numbers):
  return reduce(lcm_base, numbers, 1)
 
n = int(input())
ts = [0]*n
for i in range(n):
  ts[i] = int(input())

print(lcm_list(ts))