from fractions import gcd
from functools import reduce

input()
print(reduce(gcd, map(int, input().split())))