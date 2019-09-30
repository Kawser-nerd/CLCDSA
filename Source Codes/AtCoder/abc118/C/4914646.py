from fractions import gcd
from functools import reduce
def get_gcd(*numbers):
    return reduce(gcd, numbers)

N = int(input())
A = list(map(int, input().split()))
print(get_gcd(*A))