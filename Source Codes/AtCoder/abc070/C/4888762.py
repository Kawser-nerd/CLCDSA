import fractions
from functools import reduce
n = int(input())
t = [int(input()) for _ in range(n)]

def gcd(numbers):
  return reduce(fractions.gcd, numbers)

def lcm_base(x, y):
  return (x * y) // fractions.gcd(x, y)

def lcm(numbers):
  return reduce(lcm_base, numbers, 1)

print(lcm(t))