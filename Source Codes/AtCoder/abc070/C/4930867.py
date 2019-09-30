# import math
from fractions import gcd
from functools import reduce

N = int(input())
T = map(int, [input() for _ in range(N)])

def lcm_base(x, y):
    return (x * y) // gcd(x, y)

def lcm(numbers):
    return reduce(lcm_base, numbers, 1)

print(lcm(T))