from fractions import gcd
from functools import reduce
N, X = map(int, input().split())
print(reduce(gcd, list(map(lambda x: abs(int(x) - X), input().split()))))