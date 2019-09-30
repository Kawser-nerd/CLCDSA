n=int(input())
t=[int(input()) for _ in range(n)]
from fractions import gcd
from functools import reduce
def lcm_base(x,y):
    return ((x*y)//gcd(x,y))

def lcm(numbers):
    return reduce(lcm_base, numbers, 1)

print( lcm(t))